#pragma once
#include<ostream>
class Matrix
{
public:
	Matrix();
	~Matrix();
	Matrix(const Matrix & other);
	Matrix(const unsigned int &numOfrow, const unsigned int & numOfcolumn);
	void randomMatrix(Matrix &matr);
	void simmetricMatrix(Matrix &matr);
	void hilbertMatrix(Matrix &matr);

	void size(unsigned int numOfrows, unsigned int numOfcolumn);

	Matrix operator = (const Matrix & other);

	bool operator == (const Matrix & other) const;

	Matrix  operator + (Matrix & other);

	Matrix  operator - (const Matrix & other);

	Matrix  operator * (const Matrix & other);
	Matrix  operator * (const double & num);

	Matrix  operator ~ ();

	friend std::ostream & operator << (std::ostream & output, const Matrix & matr);
	friend std::istream & operator >> (std::istream & input, Matrix & matr);

	double * operator [] (const int & row) const;
	unsigned int getRow() const;
	unsigned int getColumn() const;
private: 
	double *pMas;
	unsigned int numOfrow;
	unsigned int numOfcolumn;

};