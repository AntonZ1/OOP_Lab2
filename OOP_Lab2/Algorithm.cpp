#include"Matrix.h"
#include"Algorithm.h"
#include<iostream>

unsigned int Algorithm::chooseElement(unsigned int column)
{	
	for (unsigned int i = column; i < pMatrix->getRow(); i++)
	{
		if ((*pMatrix)[i][column] != 0);
		return i;
	}

	throw std::logic_error("");
}

void Algorithm::swapRows(unsigned int row1, unsigned int row2)
{
	double temp = 0;
	for (unsigned int i = 0; i < pMatrix->getColumn; i++)
	{
		temp = (*pMatrix)[row1][i];
		(*pMatrix)[row1][i] = (*pMatrix)[row2][i];
		(*pMatrix)[row2][i] = temp;
	}
}

void Algorithm::normal(unsigned int row)
{
	double temp = (*pMatrix)[row][row];
	for (unsigned int j = row; j < *pMatrix->getColumn; j++)
	{
		(*pMatrix)[row][j] /= temp;
	}
}

void Algorithm::zero(unsigned int column)
{
	for (unsigned int i = column; i < *pMatrix->getRow; i++)
	{
		double temp = (*pMatrix)[i][column];
		if ((*pMatrix)[i][column] != (*pMatrix)[column][column])
		{

		}
			
	
	}
}