#pragma once

#include <fstream>
#include <ostream>


struct Matrix3x3
{
	double matrix[3][3];

	bool ReadFromFile(std::ifstream& ifs)
	{
		ifs >> matrix[0][0] >> matrix[0][1] >> matrix[0][2];
		ifs >> matrix[1][0] >> matrix[1][1] >> matrix[1][2];
		ifs >> matrix[2][0] >> matrix[2][1] >> matrix[2][2];

		return true;
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
				os << m.matrix[i][j] << " ";
			}
			os << "\n";
		}

		return os;
	}
};