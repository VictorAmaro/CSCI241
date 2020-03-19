#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string.h>
using std::cout; using std::endl;
using std::fixed; using std::left; using std::setw; using std::cerr;
using std::ostream; using std::ifstream;
using std::vector;

/********************************************************
Function: swapElements()
Arguments: A reference to a T data type called firtElement
           A reference to a T data type called secondElement
Use: Used to swap elements within the vector
Returns: Nothing
********************************************************/
template <class T>
void swapElements(T& firstElement, T& secondElement) {
	T temp; //Temp variable to hold firstElement
	temp = firstElement;
	firstElement = secondElement;
	secondElement = temp;
}

/********************************************************
Function: partition()
Arguments: A reference to a vector(set) of T data type
           A integer called start
	   A intger called end
           A predicate function called compare
Use: Selects a pivot element and then partitions the vector around the pivot
Returns: A integer, pivotIndex
********************************************************/
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)) {
	int pivotIndex = 0, //variables to hold the pivot index and the mid
	    mid = 0;
	T pivotVal;

	mid = (start + end) / 2; //finds the mid point

	swapElements(set[start],set[mid]); //calls swapElements function to swap start and mid of the vector(set)

	pivotIndex = start; //sets pivot index to start
	pivotVal = set[start]; //sets pivotVal to the vector's start subscript

	for(int scan = start + 1; scan <= end; scan++) { //sorts
		if(compare(set[scan], pivotVal)) {
			pivotIndex++;
			swapElements(set[pivotIndex],set[scan]);
		}
	}
	swapElements(set[start],set[pivotIndex]); //swaps
	return pivotIndex;
}

/********************************************************
Function: quickSort()
Arguments: A reference to a vector of T data type called set
           A integer called start
	   A integer called end
	   A predicate function called compare
Use: Performs the recursive calls to implement the quick sort algorithm.
Returns: Nothing
********************************************************/
template <class T>
void quickSort(vector<T>& set, int start, int end, bool(*compare)(const T&, const T&)) {
	int pivotPoint = 0;

	if(start < end) {
		pivotPoint = partition(set, start, end, compare);     // Get the pivot point
      		quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
      		quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
      	}
}

/********************************************************
Function: quickSort()
Arguments: A reference to a T data type vector called set
           A predicate function, with two references to T data type variables
Use: Call the recursive quick sort function
Returns: Nothing
********************************************************/
template <class T>
void quickSort(vector<T>& set, bool(*compare)(const T&, const T&)) {
	//passes the vector(set), subscript of first element(0), subscript of last element(n-1), and the comparison function
	quickSort(set, 0, set.size()-1, compare);
}

#endif
