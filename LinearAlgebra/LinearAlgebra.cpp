// LinearAlgebra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"
#include "MatrixFunctions.h"
#include "Exceptions.h"

using namespace std;

int main()
{
	//Matrix m(3, 4);
	/*Matrix y = MatrixFunctions::parse_from_user();
	cout << MatrixFunctions::to_string(y);
	Matrix x = MatrixFunctions::parse_from_user();
	cout << MatrixFunctions::to_string(x);
	cout << "First matrix + second matrix: \n";
	cout << MatrixFunctions::to_string(x + y);*/
	Matrix z = MatrixFunctions::parse_from_file("C:/Users/tristan/Documents/Visual Studio 2017/Projects/LinearAlgebra/testing.txt");
	cout << MatrixFunctions::to_string(z);
	Matrix y = MatrixFunctions::parse_from_file("C:/Users/tristan/Documents/Visual Studio 2017/Projects/LinearAlgebra/testing2.txt");
	cout << MatrixFunctions::to_string(y);
	cout << "First matrix - second matrix: \n";
	cout << MatrixFunctions::to_string(z - y);
	MatrixFunctions::ref(z);
	system("pause");
    return 0;
}

