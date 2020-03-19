#ifndef SORTS_H
#define SORTS_H

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

/**************************************************************
Function: lessThan()
Arguments: A constant reference to a T data type called item1
	   A constant reference to a T data type called item2
Purpose: Checks if item1 is less than item2
Returns: True if item1 is less than item2 or false if it's not
**************************************************************/
template<class T>
bool lessThan(const T& item1, const T& item2) {
	return (item1 < item2);
}

/**************************************************************
Function: greaterThan()
Arguments: A constant reference to a T data type called item1
	   A constant reference to a T data type called item2
Purpose: Checks if item1 is greater than item2
Returns: True if item1 is greater than item2 or false if it's not
**************************************************************/
template<class T>
bool greaterThan(const T& item1, const T& item2) {
	return (item1 > item2);
}

/**************************************************************
Function: printList()
Arguments: A integer called itemWidth to determine width a item should occupy
	   A integer called numPerLine to determine how many items will be printed per line
	   A reference to a constant vector of T data type called set
Purpose: Prints out the vector in a formatted way
Returns: Nothing
**************************************************************/
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine) {
	for(unsigned i = 0; i < set.size(); i++) {
		if( i % numPerLine == 0 && i != 0) //if numPerLine is reached, a new line is started
			cout << endl;
		cout << fixed << left << setw(itemWidth) << set.at(i) << " ";
	}
}

/**************************************************************
Function: buildList()
Arguments: A reference to a vectr of T data type called set
	   A pointer to a constant char called fileName
Purpose: Creates a vector with the passed file name (fileName)
Returns: Nothing
**************************************************************/
template<class T>
void buildList(vector<T>& set, const char* fileName) {
	T item; //variable to hold items from file
	ifstream inFile;

	inFile.open(fileName);
	if(inFile.fail()) {
		cerr << "ERROR: Could not open file!" << endl;
		exit(-1);
	}

	if(!set.empty()) //if vector(set) isn't empty, clear it out
		set.clear();

	inFile >> item; //grabs the first item from the file and stores in in item
	while(!inFile.eof()) { //continue until end of file and store items in vector(set)
		set.push_back(item);
		inFile >> item;
	}
inFile.close();
}

#endif