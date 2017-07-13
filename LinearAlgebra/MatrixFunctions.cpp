#include "stdafx.h"
#include "Matrix.h"
#include "MatrixFunctions.h"
#include "Helper.h"
#include "Exceptions.h"
#include <algorithm>
#include <fstream>

using namespace std;

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

Matrix MatrixFunctions::ref(Matrix a)
{
	// Find pivot column
	int i = 0, j = 0;
	if (a.data[0][0] == 0)
	{
		i++;
		int j = 0;
		while (a.data[i][j] == 0 && !(j == a.columns - 1 && i == a.rows - 1))
		{
			if (i == a.rows - 1)
			{
				i = 0;
				j++;
			}
			i++;
		}
		if (a.data[i][j] == 0)
		{
			// TODO
			cout << "THROW IRREDUCIBLE";
		}
		else
		{
			a = MatrixFunctions::swap_row(a, 0, i);
			i = 0;
		}
	}

	// Divide row by itself
	a = MatrixFunctions::divide_row(a, j, a.data[i][j]);

	cout << MatrixFunctions::to_string(a);

	return a;
}

Matrix MatrixFunctions::swap_row(Matrix a, int first, int second)
{
	vector<double> buffer(a.columns);
	for (int i = 0; i < a.columns; i++)
	{
		buffer[i] = a.data[second][i];
		a.data[second][i] = a.data[first][i];
		a.data[first][i] = buffer[i];
	}

	return a;
}

Matrix MatrixFunctions::divide_row(Matrix a, int row, double denominator)
{
	for (int i = 0; i < a.columns; i++)
	{
		a.data[row][i] /= denominator;
	}

	return a;
}

Matrix MatrixFunctions::add_multiple_of_row(Matrix a, int dest_row, int source_row, double multiple)
{
	for (int i = 0; i < a.columns; i++)
	{
		a.data[dest_row][i] += a.data[source_row][i] * multiple;
	}

	return a;
}