#pragma once

#include <fstream>
#include <ostream>
#include <iomanip>

class ReadMatrix3x3Exception {};

struct Matrix3x3
{
	double matrix[3][3];

	void ReadFromFile(std::ifstream& ifs)
	{
		for (int i = 0; i < 3; ++i)
		{
			ifs >> matrix[i][0] >> matrix[i][1] >> matrix[i][2];
			if (!ifs)
			{
				throw ReadMatrix3x3Exception();
			}
		}
	}

	friend Matrix3x3& operator*(Matrix3x3 const& m1, Matrix3x3 const& m2)
	{
		Matrix3x3 * result = new Matrix3x3();
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				for (int k = 0; k < 3; ++k)
				{
					result->matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
				}
			}
		}

		return *result;
	}

	friend std::ostream& operator<< (std::ostream& os, Matrix3x3 const& m)
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
};