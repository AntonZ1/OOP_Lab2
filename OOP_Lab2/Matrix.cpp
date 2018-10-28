#include"Matrix.h"
#include<iostream>
#include <string>
void Matrix::size(unsigned int numOfrow, unsigned int numOfcolumn)
{
	this->numOfrow = numOfrow;
	this->numOfcolumn = numOfcolumn;
	pMas = new double [numOfrow* numOfcolumn];
}
Matrix::Matrix()
{
	numOfrow = 1;
	numOfcolumn = 1;
	pMas= new double[numOfrow* numOfcolumn];
}
Matrix::~Matrix()
{
	if (pMas != nullptr)
	{
		delete pMas;
	}
}
unsigned int Matrix::getRow() const
{
	return numOfrow;
}
unsigned int Matrix::getColumn() const
{
	return numOfcolumn;
}
Matrix & Matrix::operator = (const Matrix & other)
{
	size(other.getRow(),other.getColumn());
	for(int i=0; i<numOfrow; i++)
	{
		for (int j = 0; j < numOfcolumn; j++) 
		{
			(pMas + i * numOfcolumn)[j] = other[i][j];
		}
	}
	
}
bool  Matrix::operator == (const Matrix & other) const
{
	if(other.getRow() != this->numOfrow || other.getColumn() != this->numOfcolumn)
	{
		return false;
	}
	else 
	{
		for (int i = 0; i < numOfrow; i++)
		{
			for (int j = 0; j < numOfcolumn; j++)
			{
				if ((pMas + i * numOfcolumn)[j] != other[i][j])
					return false;
			}
		}
	}
		return true;
}

Matrix & Matrix::operator + (const Matrix & other)
{
	for (int i = 0; i<numOfrow; i++)
	{
		for (int j = 0; j < numOfcolumn; j++)
		{
			(pMas + i * numOfcolumn)[j] += other[i][j];
		}
	}
}
Matrix & Matrix::operator - (const Matrix & other)
{
	for (int i = 0; i < numOfrow; i++)
	{
		for (int j = 0; j < numOfcolumn; j++)
		{
			(pMas + i * numOfcolumn)[j] -= other[i][j];
		}
	}
}
std::ostream & operator<<(std::ostream & output, const Matrix & matr) // !!!
{
	for (size_t row = 0; row < matr.getRow(); ++row)
	{
		for (size_t col = 0; col < matr.getColumn(); ++col)
		{
			output << matr[row][col] << "\t";
		}
		output << "\n";
	}

	return output;
}

std::istream & operator >> (std::istream & input, Matrix & matr)
{
	std::string snum;
	for (size_t row = 0; row < matr.getRow(); ++row)
	{
		std::cout << "Please input row number " << row << "." << std::endl;
		for (size_t col = 0; col < matr.getColumn(); ++col)
		{
			std::cout << "please input value of x[" << row << "][" << col << "] " << ":";
			input >> snum;
			matr[row][col] = std::atol(snum.c_str());
			std::cout << std::endl;
		}
	}

	return input;
}

double * Matrix::operator[](const int & row) const
{
	return (pMas + row * numOfcolumn);
}