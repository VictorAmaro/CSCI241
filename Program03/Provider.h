/*
File: Provider.h
Author: Victor Amaro
Logon ID: z1747708
Due Date: 2/16/16
Purpose:  Declaration for the Provider class, which represents
information about a health care provider.
*/

#ifndef PROVIDER_H
#define PROVIDER_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>
#include <stdlib.h>

using std::cout; using std::endl;
using std::ifstream; using std::ofstream;
using std::string;

class Provider //class definition for Provider
{
	public: //methods for Proivder class
	Provider();
	void print() const;
	void setAll(char[], char[], char[], char[], char[], char[], char[], char[], char[]);
	const char* getProviderNumber()const ;
	const char* getSpecialty() const;
	const char* getName() const;

	private: //data members for the Provider class
	char provNum[7];
	char specialty[41];
	char name[41];
	char firstProvAdd[41];
	char secondProvAdd[31];
	char city[21];
	char state[3];
	char zipCode[6];
	char phoneNumber[15];
};

#endif
