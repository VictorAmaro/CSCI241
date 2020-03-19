/*
File: ProviderDB.cpp
Author: Victor Amaro
Logon ID: z1747708
Due Date: 2/16/16
Purpose: Method and constructor defition for the ProviderDB.h
*/
#include "ProviderDB.h"
#include "Provider.h"
#include <fstream>
using std::ios;
using std::ws;

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
	cout << "\n**********************************" << endl
		<< "   Health Care Provider Listing   " << endl
		<< "**********************************" << endl;

	for(int i = 0; i < numOfProviders; i++)
	{
		providerDB[i].print();
	}
}

/*********************************************
Method: processTransactions()
Returns: nothing
Arguments: a pointer to a constant character
(that points to an array of characters containing the name of a file of transaction data)
Purpose: This method will read a series of transaction records until end of file.
Each record contains a transaction type, possibly followed by some additional data.
*********************************************/
void ProviderDB::processTransactions(const char* transaction)
{
 string currentTransaction;
 ifstream tranFile;
 tranFile.open("transactions.txt");
  if(tranFile.fail())
  	{
    		cout << "ERROR: Could not open. Terminating." << endl;
    		exit(-1);
  	}

tranFile >> currentTransaction; //primary read
while(!tranFile.eof()) //reads from file until the end
{
 if(currentTransaction == "all") //checks for the "all" transactions,if found, will sort by name then print
	 {
 		sortByName();
 		print();
 	 }
 if(currentTransaction == "specialty") //checks for "specialty" transactios, if found, will sort by specialty, then print out matching providers
 	{                             //with the matching specialty
 		tranFile >> ws;
 		getline(tranFile, currentTransaction);
 		sortBySpecialty();
	 	printBySpecialty(currentTransaction);
 	}
 if(currentTransaction == "number")//checks for "specialty" transactions, if found, will sort by provider numbers, then look for the given provider number, 
 	{                          //will then print out the correct message if found or not found
 		tranFile >> ws;
 		getline(tranFile, currentTransaction);
 		sortByProviderNumber();
 		int index = searchForProviderNumber(currentTransaction.c_str());
 		if(index == -1)
			{
				cout << "********************************" << endl
  		     		<< "Provider number " << currentTransaction  << " not found" << endl 
                     		<< "********************************" << endl << endl;
			}
		else
			{
  				cout << "FOUND PROVIDER NUMBER: " << currentTransaction << endl;
  				providerDB[index].print();
			}
	}
 tranFile >> currentTransaction; //secondary read
}
	tranFile.close();
}
/*********************************************
Method: searchForProviderNumber(char*)
Returns: an int
Arguments: a character array containing the provider number of the Provider to search for
Purpose: searches for a provider number using a binary sort
**********************************************/
int ProviderDB::searchForProviderNumber(const char searchNumber[])
{
	int low = 0;
	int high = numOfProviders - 1;
	int mid;

	while (low <= high)
    {
		mid = (low + high) / 2;

      	if (strcmp(searchNumber, providerDB[mid].getProviderNumber()) == 0)
         	return mid;
      	if (strcmp(searchNumber,  providerDB[mid].getProviderNumber()) == -1)
         	high = mid - 1;
      	else
         	low = mid + 1;
      }

   return -1; //returns -1 if provider number was not found
}

/*********************************************
Method: printBySpecialty(const string&)
Returns: nothing
Aruguments: const string&
Purpose: prints out providers by specialty
**********************************************/
void ProviderDB::printBySpecialty(const string& target)
{
	int count = 0;
	for(int i = 0; i < numOfProviders; i++) //will sort through providers and print the ones that match the specialty
	{
		if(strcmp(providerDB[i].getSpecialty(), target.c_str()) == 0)
			{
	 			providerDB[i].print();
 	 			count++;
			}
	}

 cout << "There are " << count << " providers with this specialty (" << target << "). They are listed directly above." << endl << endl;
}
