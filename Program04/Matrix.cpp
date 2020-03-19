#include "Matrix.h"

/***************************************************************************************************
Default Constructor
Arguments: Takes no arguments
Purpose: Sets the elements of the matrix array to the "identity matrix",
such that all the elements on the main diagonal are equal to 1 and all other elements are equal to 0
***************************************************************************************************/
Matrix::Matrix()
{
	matrix[0][0] = matrix[1][1] = 1;
	matrix[0][1] = matrix[1][0] = 0;
}

/********************************************************************************************************************
Alternate Constructor
Arguments: Takes one argument,a  two-dimensional array of integers.
Purpose: Set the elements of the matrix array to the corresponding elements in the array passed into the constructor.
*********************************************************************************************************************/
Matrix::Matrix(const int newMatrix[][2])
{
	for(int row = 0; row < 2; row++)
		for(int col = 0; col < 2; col++)
			matrix[row][col] = newMatrix[row][col];
}

/*****************************************************
Method: determinant() const
Arguments: none
Returns: The integer determinant of the Matrix object.
Purpose: Does the determinant for the Matrix object
*****************************************************/
int Matrix::determinant() const
{
	int firstDet = 0,
	    secondDet = 0,
            finalAnswer = 0;

	firstDet = matrix[0][0] * matrix[1][1];
	secondDet = matrix[0][1] * matrix[1][0];
	finalAnswer = firstDet - secondDet;

	return finalAnswer;
}

/**************************************************************************************
Function: operaator<<()
Arguments: a refernece to an ostream object and a refernce to a constant Matrix object
Returns: output
Purpose: Print the elements of the matrix separated by commas
***************************************************************************************/
ostream& operator<<(ostream& output, const Matrix& newMatrix)
{
	output << "[[" << newMatrix.matrix[0][0] << ", " << newMatrix.matrix[0][1] << "], "
			<< "[" << newMatrix.matrix[1][0] << ", " << newMatrix.matrix[1][1] << "]]";

	return output;
}

/************************************************************************
Method:operator*()
Arguments: a constant integer and a reference to a constant matrix object
Returns: the final calculation for the matrix
Purpose: Mutiplies an integer by a matrix
************************************************************************/
Matrix operator*(const int leftOp, const Matrix& rightOp)
{
	Matrix finalMatrix;
	finalMatrix.matrix[0][0] = leftOp * rightOp.matrix[0][0];
	finalMatrix.matrix[0][1] = leftOp * rightOp.matrix[0][1];
	finalMatrix.matrix[1][0] = leftOp * rightOp.matrix[1][0];
	finalMatrix.matrix[1][1] = leftOp * rightOp.matrix[1][1];

	return finalMatrix;

}

/**************************************************
Method: operator+()
Arguments: a reference to a constant Matrix object
Reutns: the result of the matrix addition
Purpose: Does the addition of the two matrices
**************************************************/
Matrix Matrix::operator+(const Matrix& rightOp) const
{
	Matrix addedMatrix;

	addedMatrix.matrix[0][0] = this->matrix[0][0] + rightOp.matrix[0][0];
	addedMatrix.matrix[0][1] = this->matrix[0][1] + rightOp.matrix[0][1];
	addedMatrix.matrix[1][0] = this->matrix[1][0] + rightOp.matrix[1][0];
	addedMatrix.matrix[1][1] = this->matrix[1][1] + rightOp.matrix[1][1];

	return addedMatrix;
}


/********************************************************************
Method: operator*()
Arguments: a constant integer
Returns: the result of the multiplied matrix
Purpose: does the calculation for the multiplication of two matrices
********************************************************************/
Matrix Matrix::operator*(const int rightOp) const
{
	Matrix finalMatrix;

 	finalMatrix.matrix[0][0] = this->matrix[0][0] * rightOp;
 	finalMatrix.matrix[0][1] = this->matrix[0][1] * rightOp;
 	finalMatrix.matrix[1][0] = this->matrix[1][0] * rightOp;
 	finalMatrix.matrix[1][1] = this->matrix[1][1] * rightOp;

	return finalMatrix;
}

/***************************************************************
Method: operator*()
Arguments: a reference to constant Matrix object
Returns: the result of the calculation
Purpose: does the calculation for matrix by matrix mutiplication
****************************************************************/
Matrix Matrix::operator*(const Matrix& rightOp) const
{
	Matrix finalMatrix;

	finalMatrix.matrix[0][0] = this->matrix[0][0] * rightOp.matrix[0][0] + this->matrix[0][1] * rightOp.matrix[1][0];
	finalMatrix.matrix[0][1] = this->matrix[0][0] * rightOp.matrix[0][1] + this->matrix[0][1] * rightOp.matrix[1][1];
	finalMatrix.matrix[1][0] = this->matrix[1][0] * rightOp.matrix[0][0] + this->matrix[1][1] * rightOp.matrix[1][0];
	finalMatrix.matrix[1][1] = this->matrix[1][0] * rightOp.matrix[0][1] + this->matrix[1][1] * rightOp.matrix[1][1];

	return finalMatrix;
}

/*********************************************************
Method: operator==()
Arguments: a reference to a constant matrix object
Returns: True or False
Purpose: Will test if the matrices are equal to each other
*********************************************************/
bool Matrix::operator==(const Matrix& rightOp) const
{
	if(this->matrix[0][0] == rightOp.matrix[0][0] &&
	   this->matrix[0][1] == rightOp.matrix[0][1] &&
	   this->matrix[1][0] == rightOp.matrix[1][0] &&
	   this->matrix[1][1] == rightOp.matrix[1][1])
		return true;
	else
		return false;
}

/**************************************************
Methos: operator!=()
Arguments: A reference to a constant matrix object
Returns: true or false
Purpose: Will test if the matrices are not equal
**************************************************/
bool Matrix::operator!=(const Matrix& rightOp) const
{
	if(this->matrix[0][0] == rightOp.matrix[0][0] &&
	   this->matrix[0][1] == rightOp.matrix[0][1] &&
	   this->matrix[1][0] == rightOp.matrix[1][0] &&
	   this->matrix[1][1] == rightOp.matrix[1][1])
		return false;
	else
		return true;
}
