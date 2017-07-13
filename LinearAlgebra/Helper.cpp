#include "stdafx.h"
#include "Helper.h"

matrix_size get_matrix_size_from_string(std::string input)
{
	std::stringstream ss(input);

	double d;
	int columns = 0;
	int rows = 1;

	while (ss >> d)
	{
		columns++;
		if (ss.peek() == ';')
		{
			rows++;
		}
		if (ss.peek() == ',')
			ss.ignore();
	}

	std::cout << rows << "," << columns << "\n";

	matrix_size instance_size;
	instance_size.rows = rows;
	instance_size.columns = columns;
	return instance_size;
}