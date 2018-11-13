#pragma once
#include"Matrix.h"
class Algorithm
{
	public:
		Algorithm() = default;
		~Algorithm();
		Algorithm(Matrix & m);
		Matrix Gaus();
		Matrix Kaczmazh(Matrix &matr, double pres);

	private:
		Matrix * pMatrix;
		unsigned int chooseElement(unsigned int column);
		void swapRows(unsigned int row1, unsigned int row2);
		bool empty_line(unsigned int row);
		void normal(unsigned int row);
		void direct_zero(const unsigned int & leadRow);
		Matrix reverce_zero();
		double skalar(Matrix &matr1, Matrix &matr2);
		double norma(Matrix &matr);
};


