// LinearAlgebra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Matrix {
public:
	Matrix(int r, int c) : rows(r), columns(c) {};
	int rows;
	int columns;
	vector<vector<double> > data;
	bool initialize();
	Matrix operator+(const Matrix& b);
};

class MatrixFunctions {
public:
	Matrix parse();
private:
	Matrix parse_from_string(string input);
};

Matrix MatrixFunctions::parse()
{
	cout << "Enter matrix values separated by commas and by semicolons: \n";

}

Matrix Matrix::operator+(const Matrix &b)
{
	Matrix m(rows, columns);
	m.initialize();

	if (b.rows != rows || b.columns != columns)
		throw "Dimension mismatch!";

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			m.data[i][j] = b.data[i][j] + data[i][j];
		}
	}

	return m;
}

bool Matrix::initialize()
{
	data.resize(rows);
	for (int i = 0; i < columns; i++)
	{
		data[i].resize(columns);
	}
	return true;
}

int main()
{
	Matrix m(3, 4);
	cout << sizeof(m) << "\n";
	system("pause");
    return 0;
}

