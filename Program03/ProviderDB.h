/*
File: ProviderDB.h
Author: Victor Amaro
Logon ID: z1747708
Due Date: 2/16/16
Purpose:  Declaration for the ProviderDB class, which represents
information about a health care provider.
*/
#ifndef PROVIDERDB_H
#define PROVIDERDB_H

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include "Provider.h"

class ProviderDB //class declaration
{
	public:
	ProviderDB();
	ProviderDB(const char*); //alternate constrcutor
	void print()const ;
	void sortByProviderNumber();
	void sortBySpecialty();
	void sortByName();
	void processTransactions(const char*);
	int searchForProviderNumber(const char searchNumber[]);
	void printBySpecialty(const string&);

	private: //data memebrs
	Provider providerDB[40]; //creates an array of providers from the provider class
	int numOfProviders = sizeof(providerDB)/sizeof(providerDB[numOfProviders]);
};

#endif
