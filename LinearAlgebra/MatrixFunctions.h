#pragma once

#ifndef MATRIXFUNCTIONS_H
#define MATRIXFUNCTIONS_H

#include "Matrix.h"

class MatrixFunctions {
public:
	static Matrix parse_from_user();
	static Matrix parse_from_file(std::string directory);
	static std::string to_string(Matrix a);
	//static Matrix ref(Matrix a);
	static Matrix rref(Matrix a);
	static Matrix rref_with_steps(Matrix a);
	static Matrix transpose(Matrix a);
	static Matrix concat_horizontal(Matrix a, Matrix b);
private:
	static Matrix parse_from_string(std::string input);
	static Matrix swap_row(Matrix a, int first, int second);
	static Matrix divide_row(Matrix a, int row, double denominator);
	static Matrix add_multiple_of_row(Matrix a, int dest_row, int source_row, double multiple);
};

#endif