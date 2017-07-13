#pragma once

#ifndef EXCEPTION_H
#define EXFEPTION_H

#include <exception>

using namespace std;
class DimensionMismatch : public exception
{
	virtual const char* what() const throw()
	{
		return "ERROR: Dimension mismatch!";
	}
};

class MatrixFormatException : public exception
{
	virtual const char* what() const throw()
	{
		return "ERROR: Matrix input is not properly formatted!";
	}
};


#endif 