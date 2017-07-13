#include "stdafx.h"
#include "Matrix.h"
#include "MatrixFunctions.h"
#include "Helper.h"
#include "Exceptions.h"
#include <algorithm>
#include <fstream>

using namespace std;

bool output = false;

std::string MatrixFunctions::to_string(Matrix a)
{
	string result;
	for (int i = 0; i < a.rows; i++)
	{
		for (int j = 0; j < a.columns; j++)
		{
			result += std::to_string(a.data[i][j]);
			result += '\t';
		}
		result += '\n';
	}

	return result;
}

Matrix MatrixFunctions::parse_from_string(string input)
{
	input.erase(std::remove_if(input.begin(), input.end(), [](char x) {return isspace(x); }), input.end());

	matrix_size size = get_matrix_size_from_string(input);

	Matrix m(size.rows, size.columns);
	m.initialize();

	stringstream s(input);

	double d;
	int r = 0, c = 0;

	while (s >> d)
	{
		m.data[r][c] = d;
		c++;
		if (s.peek() == ';')
		{
			r++;
			c = 0;
			s.ignore();
		}
		if (s.peek() == ',')
			s.ignore();
	}

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

Matrix MatrixFunctions::parse_from_file(string directory)
{
	ifstream file(directory);
	cout << "Reading from: " << directory << "\n";
	stringstream input_buffer;
	input_buffer << file.rdbuf();
	cout << "Contents of file: " << input_buffer.str() << "\n";
	Matrix m = parse_from_string(input_buffer.str());
	return m;
}

Matrix MatrixFunctions::rref(Matrix a)
{
	int j = 0;
	for (int i = 0; i < a.rows; i++)
	{
		// Check for all zero elements
		int num_of_ones = 0, num_of_zeroes = 0;
		for (int temp_row = 0; temp_row < a.rows; temp_row++)
		{
			if (a.data[temp_row][j] == 0)
				num_of_zeroes++;
			else if (a.data[temp_row][j] == 1)
				num_of_ones++;
		}
		if (num_of_ones == 1 && num_of_zeroes == a.rows - 1)
			j++;
		if (j == a.columns)
			return a;

		// Create next pivot column
		int search_row = i;
		if (i + 1 < a.rows)
			int search_row = i + 1;
		while (a.data[search_row][j] == 0 && search_row < a.rows)
			search_row++;
		a = MatrixFunctions::swap_row(a, i, search_row);

		// Divide row by pivot value
		a = MatrixFunctions::divide_row(a, i, a.data[i][j]);

		// Add selected row to others to null out
		for (int k = 0; k < a.rows; k++)
			if (k != i && a.data[k][j] != 0)
				a = MatrixFunctions::add_multiple_of_row(a, k, i, -1.0 * a.data[k][j]);
	}

	return a;
}

Matrix MatrixFunctions::rref_with_steps(Matrix a)
{
	output = true;
	a = rref(a);
	output = false;
	return a;
}

Matrix MatrixFunctions::transpose(Matrix a)
{
	Matrix result(a.columns, a.rows);
	result.initialize();

	for (int i = 0; i < a.rows; i++)
	{
		for (int j = 0; j < a.columns; j++)
		{
			result.data[j][i] = a.data[i][j];
		}
	}

	return result;
}

Matrix MatrixFunctions::swap_row(Matrix a, int first, int second)
{
	if (output)
		cout << "Swapped row " << first + 1 << " with row " << second << ".\n";
	vector<double> buffer(a.columns);
	for (int i = 0; i < a.columns; i++)
	{
		buffer[i] = a.data[second][i];
		a.data[second][i] = a.data[first][i];
		a.data[first][i] = buffer[i];
	}
	if (output)
		cout << MatrixFunctions::to_string(a);

	return a;
}

Matrix MatrixFunctions::divide_row(Matrix a, int row, double denominator)
{
	if (output)
		cout << "Divided row " << row + 1 << " by " << denominator << ".\n";
	for (int i = 0; i < a.columns; i++)
		a.data[row][i] /= denominator;
	if (output)
		cout << MatrixFunctions::to_string(a);

	return a;
}

Matrix MatrixFunctions::add_multiple_of_row(Matrix a, int dest_row, int source_row, double multiple)
{
	if (output)
		cout << "Added row " << source_row + 1 << " * " << multiple << " to row " << dest_row + 1 << ".\n";
	for (int i = 0; i < a.columns; i++)
		a.data[dest_row][i] += a.data[source_row][i] * multiple;
	if (output)
		cout << MatrixFunctions::to_string(a);

	return a;
}