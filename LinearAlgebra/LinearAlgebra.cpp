// LinearAlgebra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include "Matrix.h"

using namespace std;

Matrix MatrixFunctions::parse_from_string(string input)
{
	// First run through to catch size
	input.erase(std::remove_if(input.begin(), input.end(), [](char x) {return isspace(x); }), input.end());
	vector<string> comma_split;

	stringstream ss(input);

	double d;
	int columns = 0;
	int rows = 1;
	while (ss >> d)
	{
		columns++;
		if (ss.peek() == ';')
			rows++;
		if (ss.peek() == ',')
			ss.ignore();
	}

	cout << "Rows: " << rows << "\tColumns: " << columns << "\n";
	cout << "Fixed string: " << input;

	// Second run through to collect values
	// TODO: Temporary
	Matrix m(2, 2);
	return m;
}

Matrix MatrixFunctions::parse_from_user()
{
	cout << "Enter matrix values separated by commas and by semicolons:\n";
	std::string input_buffer;
	getline(cin, input_buffer);
	Matrix m = parse_from_string(input_buffer);
	return m;
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
	Matrix y = MatrixFunctions::parse_from_user();
	system("pause");
    return 0;
}

