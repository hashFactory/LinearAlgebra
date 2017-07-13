#pragma once

#ifndef HELPER_H
#define HELPER_H

#include <tuple>
#include <sstream>

struct matrix_size
{
	int rows;
	int columns;
};

matrix_size get_matrix_size_from_string(std::string input);

#endif