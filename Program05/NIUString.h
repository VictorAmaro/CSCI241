#ifndef NIUSTRING_H
#define NIUSTRING_H

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <iomanip>
using std::cout; using std::endl;
using std::ostream; using std::strlen;

class NIUString //class NIUString definition
{
	public: //methods for NIUString and functions
	NIUString();
	NIUString(const char* other);
	NIUString(const NIUString& other);
	~NIUString();
	NIUString& operator=(const NIUString& other);
	NIUString& operator=(const char* other);
	size_t capacity() const;
	size_t size() const;
	bool empty() const;
	void clear();
	void reserve(size_t n);
    bool operator==(const NIUString& rhs) const;
	bool operator==(const char* rhs) const;
	const char& operator[](size_t pos) const;
	char& operator[](size_t pos);
	friend ostream& operator<<(ostream& lhs, const NIUString& rhs);
	friend bool operator==(const char* lhs, const NIUString& rhs);

	private: //data members
	size_t elementsInArray;
	size_t currentLength;
	char* ch;
};
#endif
