#include "NIUString.h"

/**************************************************************************************
Function: operaator<<()
Arguments: refernece to an ostream object and a refernce to a constant NIUString object
Returns: lhs (the output)
Purpose: Print characters one at a time
**************************************************************************************/
ostream& operator<<(ostream& lhs, const NIUString& rhs) {
	for(size_t i = 0; i < rhs.currentLength; i++)
		lhs << rhs[i];
	return lhs;
}

/**************************************************************************************
Function: operator==(const char* lhs, const NIUString& rhs)
Arguments: a refernce to a constant NIUString object called rhs and a constant pointer to a C string called lhs
Returns:  return true if the characters of the C string passed in as lhs
are identical to the characters stored in the string array of the NIUString object passed in as rhs.
Purpose: checks for equality
***************************************************************************************/
bool operator==(const char* lhs, const NIUString& rhs) {
	if(strlen(lhs) != rhs.currentLength)
		return false;

	for(size_t i = 0; i < strlen(lhs); i++)
		{
			if(lhs[i] != rhs[i])
				return false;
		}
	return true;
}

/**************************************************************************************
Method: operator=(const NIUString& other)
Arguments: a refernece to an ostream object and a refernce to a constant Matrix object
Returns: a NIUString object
Purpose: assign one NIUString object (the object other) to another
(the object that called the method, which is pointed to by this)
***************************************************************************************/
NIUString& NIUString::operator=(const NIUString& other) {
	delete[] ch;

	this->elementsInArray = other.elementsInArray;
	this->currentLength = other.currentLength;

	if(this->elementsInArray == 0)
		this->ch = NULL;
	else
		this->ch = new char[elementsInArray];

	for(size_t i = 0; i < currentLength; i++)
		this->ch[i] = other.ch[i];

	return *this;

}

/**************************************************************************************
Method: operator=(const char* other)
Arguments: a constant char pointer called other
Returns: a NIUString object
Purpose: assign a C string (the string other) to an NIUString object
(the object that called the method, which is pointed to by this)
***************************************************************************************/
NIUString& NIUString::operator=(const char* other) {
	delete[] ch;

	this->elementsInArray = this-> currentLength =strlen(other);

	if(this->elementsInArray == 0)
		this->ch = NULL;
	else
		this->ch = new char[elementsInArray];

	for(size_t i = 0; i < strlen(other); i++)
		this->ch[i] = other[i];

	return *this;
}

/**************************************************************************************
Function: operator==(const NIUString& rhs) const
Arguments: a refernece to a constant NIUString object called rhs
Returns: return true if the characters stored in the string array of the object that called the method
are identical to the characters stored in the string array of the NIUString object passed in as rhs
Purpose: checks for equality
***************************************************************************************/
bool NIUString::operator==(const NIUString& rhs) const {
	if(this->currentLength != rhs.currentLength)
		return false;

	for(size_t i = 0; i < rhs.currentLength; i++)
	{
		if(this->ch[i] != rhs[i])
			return false;
	}
	return true;
}

/**************************************************************************************
Method: operator==(const char* rhs) const
Arguments: a consatant pointer to C string called rhs
Returns: return true if the characters stored in the string array of the object that called the method
are identical to the characters stored in the string array of the NIUString object passed in as rhs
Purpose: checks for equality
***************************************************************************************/
bool NIUString::operator==(const char* rhs) const {
	if(this->currentLength != strlen(rhs))
		return false;

	for(size_t i = 0; i < strlen(rhs); i++)
	{
		if(this->ch[i] != rhs[i])
			return false;
	}
	return true;
}

/*****************************************************
Method: operator[](size_t pos) const
Arguments: a size_t number representing the chosen element in  string array
Returns: element pos of the string array.
Purpose: reads the current postion of the string array
*****************************************************/
const char& NIUString::operator[](size_t pos) const {
	return ch[pos];
}

/*****************************************************
Method: operator[](size_t pos)
Arguments: a size_t number representing chosen element in string array
Returns: element pos of the string array.
Purpose: writes and returns the current position in string array
*****************************************************/
char& NIUString::operator[](size_t pos) {
	return ch[pos];
}

/*****************************************************
Method: capacity() const
Arguments: none
Returns: return the string capacity
Purpose: returns the string capacity
*****************************************************/
size_t NIUString::capacity() const {
	return elementsInArray;
}

/*****************************************************
Method: size() const
Arguments: none
Returns: return the string size.
Purpose: returns the string size
*****************************************************/
size_t NIUString::size() const {
	return currentLength;
}

/*****************************************************
Method: empty() const
Arguments: none
Returns: true if the string size is 0, otherwise return false.
Purpose: Checks if string size is empty
*****************************************************/
bool NIUString::empty() const {
	if(currentLength == 0)
		return true;
	else
		return false;
}

/*****************************************************
Method: clear()
Arguments: none
Returns: Nothing.
Purpose:set the string size and string capacity to 0 
use the delete[] operator to delete the string array.
*****************************************************/
void NIUString::clear() {
	elementsInArray = currentLength =0;
	delete[] ch;
	ch = NULL;
}

/*****************************************************
Method: reserve()
Arguments: a size_t interger called n
Returns: Nothing.
Purpose: This method modifies an object's string capacity
without changing its size or the contents of the string array
*****************************************************/
void NIUString::reserve(size_t n) {
	if(n < currentLength || n == elementsInArray)
		return;

	elementsInArray = n;
	char* temp = new char[n];

	if(elementsInArray == 0)
		clear();
	else
	{
		for(size_t i = 0; i < elementsInArray; i++)
			temp[i] = ch[i];
	}
	delete ch;
	ch = temp;
}

/***************************************************************************************************
Default Constructor
Arguments: Takes no arguments
Purpose: initialize a new NIUString object to an empty string with a capacity of 0
***************************************************************************************************/
NIUString::NIUString() {
	currentLength = elementsInArray = 0;
	ch = NULL;
}

/********************************************************************************************************************
Alternate Constructor
Arguments: Takes one argument,a constant pointer C string called char 
Purpose:  initialize a new NIUString object to the C string other.
*********************************************************************************************************************/
NIUString::NIUString(const char* other) {
	elementsInArray = currentLength = strlen(other);

	if(elementsInArray == 0)
		ch = NULL;
	else
		ch = new char[elementsInArray];

	for(size_t i = 0; i < currentLength; i++)
		ch[i] = other[i];
}

/********************************************************************************************************************
Copy Constructor
Arguments: Takes one argument,a referance to a  constant NIUString object called other.
Purpose: initialize a new NIUString object to the same string as the existing NIUString object other
*********************************************************************************************************************/
NIUString::NIUString(const NIUString& other) {
	elementsInArray = other.elementsInArray;
	currentLength = other.currentLength;

	if(elementsInArray == 0)
		ch = NULL;
	else
		ch = new char[elementsInArray];
	for(size_t i = 0; i < currentLength; i++)
		ch[i] = other.ch[i];
}

/*****************************************************
Destructor
Arguments: None
Purpose: Calls the clear() methods to delete
*****************************************************/
NIUString::~NIUString() {
	clear();
}
