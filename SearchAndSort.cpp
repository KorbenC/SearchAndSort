#include "SearchAndSort.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

SearchAndSort::SearchAndSort()
{
	prepareArr();
	copyArr();
}

void SearchAndSort::prepareArr() //fill an array with 100 elements with random values from 0 to 100
{
	srand(time(0)); //time is used as the random seed
	for (int i = 0; i <= size - 1; i++)
	{
		initialArr[i] = rand() % 101; //assigns random number in array
	}
}

void SearchAndSort::copyArr() //copies the values stored in initial array to the sorted result array
{
	for (int i = 0; i <= size - 1; i++)
	{
		sortResult[i] = initialArr[i]; //copies element by element
	}
}

void SearchAndSort::print() //outputs the initial array, sorted result array, and search result
{
	cout << "Initial Array" << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << initialArr[i] << " ";
	}
	cout << endl;

	cout << "Sorted Result Array" << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << sortResult[i] << " ";
	}
	cout << endl;

	cout << "Search Result" << endl;
	cout << searchResult << endl;
}

int SearchAndSort::linearSearch(int key)
{
	copyArr();
	int comparisons = 0;
	searchResult = -1;
	for (int i = 0; i <= size - 1; i++) //cycles through each element in the array
	{
		comparisons++;
		if (key == initialArr[i]) //if the value in array matches key then position is stored
		{
			searchResult = i;
			break; //breaks once values is found in array
		}
	}
	return comparisons;
}

int SearchAndSort::binarySearch(int key)
{
	quickSort(); //binary search requires that the array be sorted before search
	int low = 0;
	int high = size - 1;
	int loc = -1;
	int comparisons = 0;

	while (high >= low && loc == -1)
	{
		int mid = low + (high - low) / 2;
		if (sortResult[mid] == key)//checks if middle value is equal to the key
		{
			loc = mid; //if so the location is set to middle position
			comparisons++;
		}
		else if (sortResult[mid] < key)//if key is less than mid point then the key value must be in the second half of the array if it exists at all
		{
			low = mid + 1;//make the new right bound of array to the left of the midpoint
			comparisons++;
		}
		else if (sortResult[mid] > key)//if key is greater than the mid point then the key value must be in the first half of the array if it exists at all
		{
			high = mid - 1;//make the new left bound of the array to the right of the midpoint
			comparisons++;
		}
	}
	searchResult = loc;

	return comparisons;
}

int SearchAndSort::insertionSort()
{
	copyArr();

	int j, insert = 0, comparisons = 0;
	for (int i = 1; i <= size - 1; i++)
	{
		comparisons++;
		insert = sortResult[i];
		for (j = i - 1; (j >= 0) && (sortResult[j] < insert); j--) //smaller values move up in the array 
		{
			comparisons++;
			sortResult[j + 1] = sortResult[j];
		}
		sortResult[j + 1] = insert; //put the inserted value in the its the right place to be sorted
	}
	return comparisons;
}

int SearchAndSort::selectionSort()
{
	copyArr();

	int comparisons = 0;
	int first;

	for (int i = size - 1; i > 0; i--)
	{
		comparisons++;
		first = 0;
		for (int j = 1; j <= i; j++) //locates smallest between 1 and i
		{
			comparisons++;
			if (sortResult[j] < sortResult[first])
			{
				first = j;
				comparisons++;
			}
		}
		int temp = sortResult[first]; //swaps the smallest with the element in position i
		sortResult[first] = sortResult[i];
		sortResult[i] = temp;
	}
	return comparisons;
}


int SearchAndSort::bubbleSort()
{
	copyArr();
	int comparisons = 0;
	for (int i = 0; i < size - 1; i++)
	{
		comparisons++;
		for (int j = 0; j < size - 1; j++)
		{
			comparisons++;
			if (sortResult[j + 1] > sortResult[j]) //if next element is greater than the current element then swap elements
			{
				comparisons++;
				int temp = sortResult[j]; //swaps the elements
				sortResult[j] = sortResult[j + 1];
				sortResult[j + 1] = temp;
			}
		}
	}
	return comparisons;
}

int SearchAndSort::shellSort()
{
	copyArr();
	int comparisons = 0;
	int i, j, inc, tmp = 0;
	for (inc = size / 2; inc > 0; inc /= 2)
	{
		comparisons++;
		for (i = inc; i < size; i++)
		{
			comparisons++;
			tmp = sortResult[i];
			for (j = i; j >= inc; j -= inc)
			{
				comparisons++;
				if (tmp < sortResult[j - inc])
				{
					comparisons++;
					sortResult[j] = sortResult[j - inc];
				}
				else
				{
					break;
				}
			}
			sortResult[j] = tmp;
		}
	}
	return comparisons;
}

int SearchAndSort::mergeSort()
{
	copyArr();
	return mergeSortReccur(0, size - 1);  //calls the merge sort recursive function and returns the number of comparisons
}

int SearchAndSort::mergeSortReccur(int low, int high)
{
	int comparisons = 0;
	int mid = 0;
	if ((high - low) >= 1)
	{
		comparisons++;
		mid = ((low + high) / 2);
		mergeSortReccur(low, mid); //runs recursive function with first half of array
		mergeSortReccur(mid + 1, high); //runs recursive function with second half of the array
		comparisons = comparisons + merge(low, mid, mid + 1, high); //call the merge and totals the number of comparisons
	}
	return comparisons;
}

int SearchAndSort::merge(int left, int mid1, int mid2, int right) //merges two sub arrays
{
	int leftIndex = left;
	int rightIndex = mid2;
	int combinedIndex = left;
	int combined[size];
	int comparisons = 0;

	while (leftIndex <= mid1 && rightIndex <= right) //merge arrays until the end of the either array
	{
		comparisons++;
		//places larger of the two current elements into the resulting combined array
		if (sortResult[leftIndex] >= sortResult[rightIndex])
		{
			comparisons++;
			combined[combinedIndex++] = sortResult[leftIndex++];
		}
		else
		{
			comparisons++;
			combined[combinedIndex++] = sortResult[rightIndex++];
		}
	}

	if (leftIndex == mid2) //if the left array is at end
	{
		comparisons++;
		while (rightIndex <= right) //copy the remaining elements in the right array
		{
			comparisons++;
			combined[combinedIndex++] = sortResult[rightIndex++];
		}
	}
	else //if the right array is at end 
	{
		comparisons++;
		while (leftIndex <= mid1) //copy the remaing elements in the left array
		{
			comparisons++;
			combined[combinedIndex++] = sortResult[leftIndex++];
		}
	}

	//copies values back in the original result array
	for (int i = left; i <= right; i++)
		sortResult[i] = combined[i];

	return comparisons;
}

int SearchAndSort::quickSort()
{
	copyArr();
	return quickSortReccur(0, size - 1);
}

int SearchAndSort::quickSortReccur(int left, int right)
{
	int comparisons = 0;
	int i = left, j = right;
	int tmp;
	int pivot = sortResult[(left + right) / 2];
	/* partition */
	while (i <= j)
	{
		comparisons++;
		while (sortResult[i] < pivot)
		{
			comparisons++;
			i++;
		}
		while (sortResult[j] > pivot)
		{
			comparisons++;
			j--;
		}
		if (i <= j)
		{
			comparisons++;
			tmp = sortResult[i];
			sortResult[i] = sortResult[j];
			sortResult[j] = tmp;
			i++;
			j--;
		}

	};
	/* recursion */
	if (left < j)
	{
		comparisons++;
		quickSortReccur(left, j);
	}
	if (i < right)
	{
		comparisons++;
		quickSortReccur(i, right);
	}

	return comparisons;

}