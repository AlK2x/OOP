#pragma once

#include <iostream>
#include <fstream>
#include <ostream>
#include <iomanip>

class Matrix3x3ReadingException : public std::runtime_error
{
public:
	Matrix3x3ReadingException(std::string const& descr)
		:std::runtime_error(descr)
	{
	};
};

struct Matrix3x3
{
	double matrix[3][3];

	Matrix3x3();

	~Matrix3x3() {}

	const Matrix3x3 operator*(Matrix3x3 const& m) const;
};

std::ostream& operator<< (std::ostream& os, Matrix3x3 const& m);
std::istream& operator>> (std::istream& is, Matrix3x3& m);