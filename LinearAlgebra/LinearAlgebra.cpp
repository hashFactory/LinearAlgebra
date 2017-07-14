// LinearAlgebra.cpp : Defines the entry point for the console application.
//

// Implemented functions: +, -, *, parse_from_user, parse_from_file, to_string, rref, transpose, concat_horizontal, concat_vertical, create_identity, ...
//								invert, parse_from_string, swap_row, divide_row, add_multiple_of_row

#include "stdafx.h"
#include "Matrix.h"
#include "MatrixFunctions.h"
#include "Exceptions.h"

using namespace std;

int main()
{
	//Matrix m(3, 4);
	/*
	Matrix y = MatrixFunctions::parse_from_user();
	cout << MatrixFunctions::to_string(y);
	
	Matrix x = MatrixFunctions::parse_from_user();
	cout << MatrixFunctions::to_string(x);
	cout << "First matrix + second matrix: \n";
	cout << MatrixFunctions::to_string(x + y);*/
	Matrix z = MatrixFunctions::parse_from_file("C:/Users/tristan/Documents/Visual Studio 2017/Projects/LinearAlgebra/testing.txt");
	cout << MatrixFunctions::to_string(z);
	Matrix y = MatrixFunctions::parse_from_file("C:/Users/tristan/Documents/Visual Studio 2017/Projects/LinearAlgebra/testing2.txt");
	cout << MatrixFunctions::to_string(y);
	//cout << "First matrix - second matrix: \n";
	//cout << MatrixFunctions::to_string(y - z);
	cout << MatrixFunctions::invert(z);
	//MatrixFunctions::rref_with_steps(z);

	system("pause");
    return 0;
}

