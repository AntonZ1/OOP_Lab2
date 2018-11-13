#include"Matrix.h"
#include<iostream>
#include <string>
#include <time.h>

void Matrix::size(unsigned int numOfrow, unsigned int numOfcolumn)
{
	this->numOfrow = numOfrow;
	this->numOfcolumn = numOfcolumn;
}
Matrix::Matrix()
{
	numOfrow = 1;
	numOfcolumn = 1;
	pMas= new double[numOfrow* numOfcolumn];
}

Matrix::Matrix(const unsigned int & numOfrow, const unsigned int & numOfcolumn)
{
	size(numOfrow, numOfcolumn);
	pMas = new double[numOfrow* numOfcolumn];
}

Matrix::Matrix(const Matrix & other)
{
	*this = other;
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
Matrix Matrix::operator = (const Matrix & other)
{
	double temp = 123123;
	size(other.getRow(),other.getColumn());
	pMas = new double[numOfrow* numOfcolumn];
	for(int i=0; i<numOfrow; i++)
	{
		for (int j = 0; j < numOfcolumn; j++) 
		{
			temp = other[i][j];
			(pMas + i * numOfcolumn)[j] = other[i][j];
		}
	}
	return *this;
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

Matrix Matrix::operator + (Matrix & other)
{
	Matrix A;
	A.size(other.numOfrow,other.numOfcolumn);

	for (int i = 0; i<numOfrow; i++)
	{
		for (int j = 0; j < numOfcolumn; j++)
		{
			A[i][j] = (pMas + i * numOfcolumn)[j] + other[i][j];
		}
	}
	return A;
}
Matrix Matrix::operator - (const Matrix & other)
{
	Matrix A;
	for (int i = 0; i < numOfrow; i++)
	{
		for (int j = 0; j < numOfcolumn; j++)
		{
			A[i][j]=(pMas + i * numOfcolumn)[j] - other[i][j];
		}
	}
	return A;
}

Matrix Matrix::operator * (const Matrix & other)
{
	Matrix A;
	unsigned int res = 0;
	if (other.getRow() == this->getColumn())
	{
		for (int i = 0; i < numOfrow; i++)
		{
			for (int j = 0; j < numOfcolumn; j++)
			{
				
				for (int t = 0; t < j; t++)
				{
					res+= (pMas + i * numOfcolumn)[t] * other[t][j];
				}
				A[i][j] = res;
				res = 0;
			}

		}
	}
	return A;
}

Matrix Matrix::operator * (const double & num)
{
	Matrix A;
	for (int i = 0; i < numOfrow; i++)
	{
		for (int j = 0; j < numOfcolumn; j++)
		{
			A[i][j]=(pMas + i * numOfcolumn)[j] * num;
			
		}
	}
	return A;
}
Matrix Matrix::operator ~()
{
	
	double temp = 0;
	for (int i = 0; i < numOfrow; i++)
	{
		for (int j = 0; j < numOfcolumn; j++)
		{
			temp = (pMas + i * numOfcolumn)[j];
			(pMas + i * numOfcolumn)[j]= (pMas +j * numOfcolumn)[i];
			(pMas + j * numOfcolumn)[i] = temp;
		}
	}
	return *this;
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
			matr[row][col] = std::atof(snum.c_str());
			std::cout << std::endl;
		}
	}

	return input;
}

double * Matrix::operator[](const int & row) const
{
	return (pMas + row * numOfcolumn);
}

void Matrix::randomMatrix(Matrix &matr)
{
	srand(time(0));

	for (int i = 0; i<numOfrow; i++)
	{
		for (int j = 0; j < numOfcolumn; j++)
		{
			matr[i][j] = 1 + rand() % 200;
		}
	}
}

void Matrix::simmetricMatrix(Matrix &matr)
{
	srand(time(0));

	for (int i = 0; i <numOfrow; i++)
	{
		for (int j = 0; j < numOfcolumn; j++)
		{
			if (i == j)
			{
				matr[i][j] = 1 + rand() % 200;
			}
			else
			{
				matr[i][j] = matr[j][i] = 1 + rand() % 200;
			}
		}
	}
}

void Matrix::hilbertMatrix(Matrix &matr)
{
	for (int i = 1; i <= numOfrow; i++)
	{
		for (int j = 1; j <= numOfcolumn; j++)
		{
			matr[i - 1][j - 1] = 1.0 / double(i + j - 1);
		}
	}
}