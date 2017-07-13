#include "stdafx.h"
#include "Matrix.h"
#include "MatrixFunctions.h"
#include "Exceptions.h"
#include "Helper.h"
#include <iostream>

Matrix Matrix::operator+(const Matrix &b)
{
	Matrix m(rows, columns);
	m.initialize();

	if (b.rows != rows || b.columns != columns)
	{
		DimensionMismatch _ex_DM;
		try
		{
			throw _ex_DM;
		}
		catch (exception& e)
		{
			cout << e.what() << "\n";
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			m.data[i][j] = b.data[i][j] + data[i][j];
		}
	}

	return m;
}

Matrix Matrix::operator-(const Matrix &b)
{
	Matrix m(rows, columns);
	m.initialize();

	if (b.rows != rows || b.columns != columns)
	{
		DimensionMismatch _ex_DM;
		try
		{
			throw _ex_DM;
		}
		catch (exception& e)
		{
			cout << e.what() << "\n";
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			m.data[i][j] = data[i][j] - b.data[i][j];
		}
	}

	return m;
}

Matrix Matrix::operator*(const Matrix &b)
{
	Matrix m(rows, b.columns);
	m.initialize();

	if (columns != b.rows)
	{
		DimensionMismatch _ex_DM;
		try
		{
			throw _ex_DM;
		}
		catch (exception& e)
		{
			cout << e.what() << "\n";
		}
	}

	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.columns; j++)
		{
			double buffer = 0;
			for (int _i = 0; _i < columns; _i++)
				buffer += data[i][_i] * b.data[_i][j];
			m.data[i][j] = buffer;
		}
	}

	return m;
}

ostream& operator<<(ostream& out, const Matrix& b)
{
	return out << MatrixFunctions::to_string(b);
}

bool Matrix::initialize()
{
	data.resize(rows);
	for (int i = 0; i < rows; i++)
	{
		data[i].resize(columns);
	}
	return true;
}