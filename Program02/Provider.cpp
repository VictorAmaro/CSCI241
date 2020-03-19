/*
File: Provider.cpp
Author: Victor Amaro
Logon ID: z1747708
Due Date: 2/16/16
Purpose: Method and constructor definition for the Provider.h
*/
#include "Provider.h"
/**********************************************
The default constructor for the provider class
***********************************************/
Provider::Provider()
{
}

/***************************************
Method: print()
returns: nothing
purpose: when called, will print
out all the data members in a formatted way
***************************************/
 void Provider::print() const 
{
	cout << "#" << provNum << endl
		<< name << endl
		<< specialty << endl
		<< firstProvAdd << endl
		<< secondProvAdd << endl
		<< city << ", " << state << " " << zipCode << endl
		<< phoneNumber << endl << endl;
}

/***************************************
Method: getProviderNumber()
returns: provNum
Purpose: returns the provider number
that is currently set
***************************************/
const char* Provider::getProviderNumber() const 
{
	return provNum;
}

/***************************************
Method: getSpecialty()
returns: specialty
purpose: returns the specialty that is
currently set
***************************************/
const char* Provider:: getSpecialty() const
{
	return specialty;
}

/************************************
Method: getName()
returns: name
purpose: returns the name that is
currently set
************************************/
const char* Provider::getName() const
{
	return name;
}