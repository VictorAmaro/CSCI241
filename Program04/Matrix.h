#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <stdlib.h>

using std::cout; using std::endl;
using std::ostream;

class Matrix //Class Defintion for Matrix
{
	public:
		Matrix();
        Matrix(const int[][2]);
        Matrix operator+(const Matrix&) const;
        Matrix operator*(const Matrix&) const;
		Matrix operator*(const int)const;
        bool operator==(const Matrix&) const;
        bool operator!=(const Matrix&) const;
		friend ostream& operator<<(ostream&, const Matrix&);
		friend Matrix operator*(const int,const Matrix&);
		int determinant() const;

	private:
		int matrix[2][2];
};
#endif
