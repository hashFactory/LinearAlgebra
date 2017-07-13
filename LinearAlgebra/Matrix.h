#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
public:
	Matrix(int r, int c) : rows(r), columns(c) {};
	int rows;
	int columns;
	std::vector<std::vector<double> > data;
	bool initialize();

	Matrix operator+(const Matrix& b);
	Matrix operator-(const Matrix& b);

};

#endif // !MATRIX_H