/*
File: ProviderDB.cpp
Author: Victor Amaro
Logon ID: z1747708
Due Date: 2/16/16
Purpose: Method and constructor defition for the ProviderDB.h
*/
#include "ProviderDB.h"
#include "Provider.h"
using std::ios;

/****************************************
Alternate constructor: Provider(const char*)
Opens binary file, prints out error message
if could not open. 
****************************************/
ProviderDB::ProviderDB(const char* fileName)
{
	ifstream inFile;
	inFile.open(fileName, ios::binary);
	if (inFile.fail())
	{
		cout << "ERROR: Could not open '" << fileName << "'. Terminating." << endl;
		exit(-1);
	}
	inFile.read((char*)this, sizeof(ProviderDB));
	inFile.close();
}

/****************************************
Constructor: Will set the number of providers
to zero
*****************************************/
ProviderDB::ProviderDB()
{
	numOfProviders = 0;
}

/****************************************
Method:sortByProviderNumber()
returns: nothing
arguments: none
purpose:will sort the providers by their
provider number using the  insertion sort method in
ascending order
****************************************/
void ProviderDB::sortByProviderNumber()
{
	int i, j;
	Provider temp;
	for(i = 1; i < numOfProviders; i++)
	{
		temp = providerDB[i];
		for(j = i; (j > 0) && (strcmp(providerDB[j-1].getProviderNumber(), temp.getProviderNumber()) > 0); j--)
			providerDB[j] = providerDB[j-1];

		providerDB[j] = temp;
	}
}

/****************************************
Method:sortByName()
returns: nothing
arguments: none
purpose:will sort the providers by their
name using the  insertion sort method in
ascending order
****************************************/
void ProviderDB::sortByName()
{
	int i, j;
	Provider temp;
	for(i = 1; i < numOfProviders; i++)
	{
		temp = providerDB[i];
		for(j = i; (j > 0) && (strcmp(providerDB[j-1].getName(), temp.getName()) > 0 ); j--)
			providerDB[j] = providerDB[j-1];

		providerDB[j] = temp;
	}
}

/****************************************
Method:sortBySpecialty()
returns: nothing
arguments: none
purpose:will sort the providers by their
specialty using the  insertion sort method in
desending order
****************************************/
void ProviderDB::sortBySpecialty()
{
	int i, j;
	Provider temp;
	for(i = 1; i < numOfProviders; i++)
	{
		temp = providerDB[i];
		for(j = i; (j > 0) && (strcmp(providerDB[j-1].getSpecialty(), temp.getSpecialty()) <  0 ); j--)
			providerDB[j] = providerDB[j-1];

		providerDB[j] = temp;
	}
}

/****************************************
Method: print()
returns: nothing
arguments: none
purpose: calls the print() from Provider.cpp/h
and will print out the providers
****************************************/
void ProviderDB::print() const 
{
	cout << "**********************************" << endl
		<< "   Health Care Provider Listing   " << endl
		<< "**********************************" << endl;

	for(int i = 0; i < numOfProviders; i++)
	{
		providerDB[i].print();
	}
}
