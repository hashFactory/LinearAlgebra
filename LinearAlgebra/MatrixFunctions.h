#pragma once

#ifndef MATRIXFUNCTIONS_H
#define MATRIXFUNCTIONS_H

#include "Matrix.h"

class MatrixFunctions {
public:
	static Matrix parse_from_user();
	static std::string to_string(Matrix a);
private:
	static Matrix parse_from_string(std::string input);
};

#endif