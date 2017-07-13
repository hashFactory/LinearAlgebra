#include "stdafx.h"
#include "Helper.h"
#include "Exceptions.h"

matrix_size get_matrix_size_from_string(std::string input)
{
	// Returns the dimensions of a matrix input string
	string item;
	int rows = 0, cols = 0, final_cols = 0;
	stringstream thing(input);
	for (string line; getline(thing, line, ';'); )
	{
		istringstream in(line);
		cols = 0;
		while (getline(in, item, ','))
			cols++;
		if (rows == 0)
			final_cols = cols;
		else if (cols != final_cols)
		{
			MatrixFormatException _ex_MFE;
			try
			{
				throw _ex_MFE;
			}
			catch (exception& e)
			{
				cout << e.what() << "\n";
			}
		}
		rows++;
	}

	matrix_size instance_size;
	instance_size.rows = rows;
	instance_size.columns = cols;
	return instance_size;
}