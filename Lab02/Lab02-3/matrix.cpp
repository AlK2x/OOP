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