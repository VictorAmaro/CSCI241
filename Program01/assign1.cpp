//CSCI 241 - Assignment 1 - Spring 2016
//Progammer: Victor maro
//Z-ID: z1747708
//Section: 2
//TA: Anil Murahari
//Date Due: Feb 9, 2016
//Purpose: This assignment is an exercise in writing, compiling, and executing a 
//C++ program on the departmental UNIX system. It also covers the basics of object-oriented 
//programming and the manipulation of C and C++ strings

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>
#include <stdlib.h>

using std::cout; using std::endl;
using std::ifstream; using std::ofstream;
using std::string;

#define ARRAY_SIZE 50 //sets a constant to be used for arrays

class Provider //class definition for Provider
{
	public: //methods for Proivder class
	Provider();
	void print();
	void setAll(char[], char[], char[], char[], char[], char[], char[], char[], char[]);
	 
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

int main()
{
	ifstream inFile;
	inFile.open("providers.csv"); //opens the providers.csv file
	if(inFile.fail()) //if file can not be open, error message will display
	{
		cout << "ERROR: Could not open file" << endl;
		exit(-1);
	}
	
	Provider theProvider[50]; //creates an array of providers
	int count = 0; //variables to be used to place the necessary information, a counter, and a token variable
	char currentLine[256];
	char* token;
	char providerNumber[ARRAY_SIZE];
	char specialty [ARRAY_SIZE];
	char firstProviderAddress [ARRAY_SIZE];
	char secondProviderAddress [ARRAY_SIZE];
	char city [ARRAY_SIZE];
	char state [ARRAY_SIZE];
	char zipCode [ARRAY_SIZE];
	char phoneNumber [ARRAY_SIZE];
	char lastName [ARRAY_SIZE];
	char firstName[ARRAY_SIZE];
	char intial[ARRAY_SIZE];
	char title[ARRAY_SIZE];

	inFile.getline(currentLine, 256); //grabs first line of the file
	while(!inFile.eof()) //loop that will grab  the next line as long as there is more to grab
	{
		token = strtok(currentLine, ","); //all the parsing will be done within this while loop
		strcpy(providerNumber, token);

		token = strtok(NULL, ",");
		strcpy(specialty, token);

		token = strtok(NULL, ",");
		strcpy(lastName, token);
		token = strtok(NULL, ",");
		strcpy(firstName, token);
		token = strtok(NULL, ","); // Grab what is the middle initial OR the title
		if(strchr(token, '.')!= NULL) // If it�s the title, skip this part
		{
			strcpy(intial, token);
			token = strtok(NULL, ",");
		}
		strcpy(title, token);
		strcat(lastName, ", "); //concatenates the first name, last name, intial, (if one is present) and title into one string with spacing
		strcat(lastName, firstName);
		strcat(lastName, ", ");
		strcat(lastName, intial);
		strcat(lastName, ", ");
		strcat(lastName, title);

		token = strtok(NULL, ",");
		strcpy(firstProviderAddress, token);
		token = strtok(NULL, ",");
		strcpy(secondProviderAddress, token);

		token = strtok(NULL, ",");
		strcpy(city, token);

		token = strtok(NULL, ",");
		strcpy(state, token);

		token = strtok(NULL, ",");
		strcpy(zipCode, token);

		token = strtok(NULL, ",");
		strcpy(phoneNumber, token);

		theProvider[count].setAll(providerNumber, specialty, lastName, firstProviderAddress, secondProviderAddress, city, state,
								   zipCode, phoneNumber); //sets the variables 
		count++; 
		inFile.getline(currentLine, 256); //secondary read
	}

	for(int i =0; i < count; i++) //loop that will print the providers
		theProvider[i].print();

	inFile.close();
	return 0;
}


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
out all the data members in a
formatted way
***************************************/
void Provider::print()
{
	cout << "#" << provNum << endl
		<< name << endl
		<< specialty << endl
		<< firstProvAdd << endl
		<< secondProvAdd << endl
		<< city << ", " << state << " " << zipCode << endl
		<< phoneNumber << endl << endl;
}
/*******************************************************
method: setAll()
returns: nothing
parameters: nine char arrays representing different values from the .csv 
purpose: sets the passed parameters to the correct data members
*******************************************************/
void Provider::setAll(char _providerNumber[], char _specialty[], char _name[], char _firstProviderAddress[], 
                      char _secondProviderAddress[], char _city[], char _state[], char _zipCode[], char _phoneNumber[]) 
{
	strcpy(provNum, _providerNumber);
	strcpy(specialty, _specialty);
	strcpy(name, _name);
	strcpy(firstProvAdd, _firstProviderAddress);
	strcpy(secondProvAdd, _secondProviderAddress);
	strcpy(city, _city);
	strcpy(state, _state);
	strcpy(zipCode, _zipCode);
	strcpy(phoneNumber, _phoneNumber);
}
