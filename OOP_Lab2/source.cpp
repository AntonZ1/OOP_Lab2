#include<iostream>
#include "Matrix.h"
#include "Algorithm.h"

using namespace std;

int main()
{
	Matrix M,A;

	M.size(3, 4);
	//cin >> M;

	Algorithm alg;
	//cout << alg.Gaus();
	M.randomMatrix(M);

	cout << M << endl;

	A = M + M;

	cout << A << endl;

	cout << alg.Kaczmazh(M,0.000001) << endl;

	cout << "done";

	system("pause");

	return 0;
}