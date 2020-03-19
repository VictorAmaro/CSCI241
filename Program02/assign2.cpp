/*************************************
CSCI 241 - Assignment 2 - Spring 2016
Progammer: Victor Amaro
Z-ID: z1747708
Section: 2
TA: Anil Murahari
Date Due: Feb 16, 2016
Purpose:to write a main program and several
classes to create and print a small database
of health care provider data
************************************/
#include "Provider.h"
#include "ProviderDB.h"

int main()
{
	ProviderDB DB("providerdb");
	DB.print();

	DB.sortByProviderNumber();
	DB.print();

	DB.sortBySpecialty();
	DB.print();

	DB.sortByName();
	DB.print();

	return 0;
}
