#ifndef SEARCH_AND_SORT_H
#define SEARCH_AND_SORT_H

class SearchAndSort
{
public:
	SearchAndSort();
	void prepareArr();
	void copyArr();
	void print();
	int linearSearch(int); //takes in key for search and returns number of comparisons
	int binarySearch(int); //takes in key for search and returns number of comparisons
	int insertionSort(); //returns number of comparisons
	int selectionSort(); //returns number of comparisons
	int bubbleSort(); //returns number of comparisons
	int shellSort();//returns number of comparisons
	int mergeSort(); //returns number of comparisons
	int quickSort();//returns number of comparisons

private:
	static const int size = 100;
	int initialArr[size];
	int sortResult[size];
	int searchResult;
	int mergeSortReccur(int, int); //recursive function used for merge sort
	int merge(int, int, int, int); //utility function for the merge sort that merges two sub arrays
	int quickSortReccur(int, int);//utility function for quick sort that partitions and recursive function
};

#endif 