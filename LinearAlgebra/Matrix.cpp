#include "stdafx.h"
#include "Matrix.h"
#include "Exceptions.h"
#include "Helper.h"

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

bool Matrix::initialize()
{
	data.resize(rows);
	for (int i = 0; i < rows; i++)
	{
		data[i].resize(columns);
	}
	return true;
}