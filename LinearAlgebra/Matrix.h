#pragma once

#include <vector>
#include <string>

#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:
	Matrix(int r, int c) : rows(r), columns(c) {};
	int rows;
	int columns;
	std::vector<std::vector<double> > data;
	bool initialize();
	Matrix operator+(const Matrix& b);

};

class MatrixFunctions {
public:
	static Matrix parse_from_user();
private:
	static Matrix parse_from_string(std::string input);
};

#endif // !MATRIX_H