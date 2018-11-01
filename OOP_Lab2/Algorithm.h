#pragma once
#include"Matrix.h"
class Algorithm
{
	public:
		Algorithm();
		~Algorithm();
		
		Matrix Gaus();

	private:
		Matrix * pMatrix;
		unsigned int chooseElement(unsigned int column);
		void swapRows(unsigned int row1, unsigned int row2);
		void normal(unsigned int row);
		void zero(unsigned int row);
};


