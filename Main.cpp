#include <iostream>
#include "SearchAndSort.h"

using namespace std;

void main()
{
	//initilizes the variables to store the number of comparisons
	int linearSearchComp = 0;
	int binarySearchComp = 0;
	int insertionSortComp = 0;
	int selectionSortComp = 0;
	int bubbleSortComp = 0;
	int shellSortComp = 0;
	int mergeSortComp = 0;
	int quickSortComp = 0;

	for (int i = 0; i < 50; i++) //runs 50 instances of the various sorting and searching methods on data
	{
		SearchAndSort arr;
		cout << "Initial Conditions" << endl;
		arr.print();

		cout << endl << "After Linear Search" << endl;
		linearSearchComp = linearSearchComp + arr.linearSearch(50);
		arr.print();

		cout << endl << "After Binary Search" << endl;
		binarySearchComp = binarySearchComp + arr.binarySearch(50);
		arr.print();

		cout << endl << "After Insertion Sort" << endl;
		insertionSortComp = insertionSortComp + arr.insertionSort();
		arr.print();

		cout << endl << "After Selection Sort" << endl;
		selectionSortComp = selectionSortComp + arr.selectionSort();
		arr.print();

		cout << endl << "After Bubble Sort" << endl;
		bubbleSortComp = bubbleSortComp + arr.bubbleSort();
		arr.print();

		cout << endl << "After Shell Sort" << endl;
		shellSortComp = shellSortComp + arr.shellSort();
		arr.print();

		cout << endl << "After Merge Sort" << endl;
		mergeSortComp = mergeSortComp + arr.mergeSort();
		arr.print();

		cout << endl << "After Quick Sort" << endl;
		quickSortComp = quickSortComp + arr.quickSort();
		arr.print();
	}

	//determines the average amount of comparisons that are used for each searching and sorting algorithms
	linearSearchComp = linearSearchComp / 50;
	binarySearchComp = binarySearchComp / 50;
	insertionSortComp = insertionSortComp / 50;
	selectionSortComp = selectionSortComp / 50;
	bubbleSortComp = bubbleSortComp / 50;
	shellSortComp = shellSortComp / 50;
	mergeSortComp = mergeSortComp / 50;
	quickSortComp = quickSortComp / 50;

	//outputs the averge number of comparisons performed for each searching and sorting algorithms
	cout << "Average Number of Comparisons for Linear Search " << linearSearchComp << endl;
	cout << "Average Number of Comparisons for Binary Search " << binarySearchComp << endl;
	cout << "Average Number of Comparisons for Insertion Sort " << insertionSortComp << endl;
	cout << "Average Number of Comparisons for Selection Sort " << selectionSortComp << endl;
	cout << "Average Number of Comparisons for Bubble Sort " << bubbleSortComp << endl;
	cout << "Average Number of Comparisons for Shell Sort " << shellSortComp << endl;
	cout << "Average Number of Comparisons for Merge Sort " << mergeSortComp << endl;
	cout << "Average Number of Comparisons for Quick Sort " << quickSortComp << endl;

}