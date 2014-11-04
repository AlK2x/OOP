#include "matrix.h"

Matrix3x3::Matrix3x3()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			matrix[i][j] = 0.0;
		}
	}
}

const Matrix3x3 Matrix3x3::operator*(Matrix3x3 const& m) const
{
	Matrix3x3 result;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				result.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
			}
		}
	}

	return result;
}

std::ostream& operator<< (std::ostream& os, Matrix3x3 const& m)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			os << std::setprecision(3) << m.matrix[i][j] << " ";
		}
		os << "\n";
	}

	return os;
}

std::istream& operator>> (std::istream& is, Matrix3x3& m)
{
	for (int i = 0; i < 3; ++i)
	{
		is >> m.matrix[i][0] >> m.matrix[i][1] >> m.matrix[i][2];
		if (!is)
		{
			throw Matrix3x3ReadingException("Read matrix from file exception.\n");
		}
	}

	return is;
}
