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
	for (unsigned int i = 0; i < pMatrix->getColumn(); i++)
	{
		temp = (*pMatrix)[row1][i];
		(*pMatrix)[row1][i] = (*pMatrix)[row2][i];
		(*pMatrix)[row2][i] = temp;
	}
}


bool Algorithm::empty_line(unsigned int row)
{
	for (int col = 0; col < pMatrix->getColumn(); ++col)
	{
		if ((*pMatrix)[row][col] != 0)
		{
			if (col == pMatrix->getColumn())
				break;

			return false;
			break;
		}
	}
	return true;
}

void Algorithm::normal(unsigned int row)
{
	double temp = (*pMatrix)[row][row];
	for (unsigned int j = row; j < pMatrix->getColumn(); j++)
	{
		(*pMatrix)[row][j] /= temp;
	}
}

void Algorithm::direct_zero(const unsigned int & leadRow)
{
	if (leadRow >= pMatrix->getRow() - 1)	return;

	unsigned int j = leadRow;
	double temp = 0;
	for (int i = leadRow + 1; i < pMatrix->getRow(); i++)
	{
		j = leadRow;
		temp = (*pMatrix)[i][j];
		for (; j < pMatrix->getColumn(); j++)
		{
			(*pMatrix)[i][j] -= (*pMatrix)[leadRow][j] * temp;
		}
	}
}

Matrix Algorithm::reverce_zero()
{
	Matrix res(1, pMatrix->getColumn() - 1);
	int lead_row = pMatrix->getRow() - 1;
	double Ai_lead, temp;
	for (int j = pMatrix->getColumn() - 2; j >= 0; j--, lead_row--)
	{
		Ai_lead = (*pMatrix)[lead_row][pMatrix->getColumn() - 1];
		(res)[0][pMatrix->getColumn() - 2 - j] = (Ai_lead);
		for (int i = lead_row; i > 0; --i)
		{
			temp = (*pMatrix)[i - 1][j];
			(*pMatrix)[i - 1][pMatrix->getColumn() - 1] -= Ai_lead * temp;
			(*pMatrix)[i - 1][j] -= (*pMatrix)[lead_row][j] * temp;
		}
	}

	return res;
}

Algorithm::~Algorithm()
{
	delete pMatrix;
}

Algorithm::Algorithm(Matrix & m)
{
	pMatrix = new Matrix(m);
}


Matrix Algorithm::Gaus()
{
	unsigned int k = 0;
	unsigned int next_line = k;

	unsigned int rowOfelement;

	for (; k < pMatrix->getRow(); k++, next_line++)
	{
		if (!empty_line(k))
		{
			rowOfelement = chooseElement(k);
			swapRows(rowOfelement, next_line);
			//std::cout << *pMatrix;
			normal(next_line);
			//std::cout << *pMatrix;
			direct_zero(next_line);
			//std::cout << *pMatrix;
		}
	}

	return reverce_zero();
}
	


Matrix Algorithm::Kaczmazh(Matrix &matr,double pres)//точність-pres
{
	Matrix a,b,c;
	a.size(1,matr.getColumn()- 1);
	b.size(1, matr.getColumn() - 1);
	c.size(1, matr.getColumn() - 1);
	double coef;
	int Iterator = 0;
	for(int i=0;i<matr.getColumn() - 1;i++)
	{
		a[0][i] = matr[0][i];
	}
	for(int i=0;i<matr.getColumn() - 1;i++)
	{
		c[0][i] = 1;
	}
	while(norma(c)>pres)
	{
		Matrix temp;
		temp.size(1, matr.getColumn() - 1);
		for(int i=0;i<matr.getColumn() - 1;i++)
		{
			temp[0][i] = matr[Iterator][i];
		}
		coef = (matr[Iterator][matr.getColumn() - 1] - skalar(temp, a))/(norma(temp)*(norma(temp)));
		temp = temp * coef;
		b = a + temp;
		c = b - a;
		a = b;
		if(Iterator<a.getColumn()-1)
		{
			Iterator++;
		}
		else Iterator = 0;
	}
	return a;
}

double Algorithm::Algorithm::skalar(Matrix &matr1, Matrix &matr2)
{
	double sum = 0;
	for(int i=0;i<matr1.getColumn()-1;i++)
	{
		sum += matr1[0][i] * matr2[0][i];
	}
	return sum;
}

double Algorithm::norma(Matrix &matr)
{
	double sum = 0;
	for(int i=0; i<matr.getColumn()-1;i++)
	{
		sum += matr[0][i]*matr[0][i];
	}
	return sqrt(sum);
}