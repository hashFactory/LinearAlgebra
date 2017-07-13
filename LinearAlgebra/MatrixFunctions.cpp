#include "stdafx.h"
#include "Matrix.h"
#include "MatrixFunctions.h"
#include "Helper.h"
#include <algorithm>

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