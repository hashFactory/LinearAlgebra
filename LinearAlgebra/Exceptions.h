#pragma once

#ifndef EXCEPTION_H
#define EXFEPTION_H

#include <exception>

using namespace std;
class DimensionMismatch : public exception
{
	virtual const char* what() const throw()
	{
		return "Dimension mismatch!";
	}
};


#endif 