#include "matrix.h"

using namespace std;

ostream& operator<< (ostream& os, Matrix3x3 const& m)
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

istream& operator>> (istream& is, Matrix3x3& m)
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

const Matrix3x3 ReadMatrixFromFile(const char* filename)
{
	string matrixFilename(filename);
	ifstream ifs(matrixFilename);
	if (!ifs.is_open())
	{
		throw runtime_error("Unable to open file: " + matrixFilename);
	}

	Matrix3x3 matrix;
	ifs >> matrix;
	return matrix;
}

int main(int argc, char * argv[])
{
	if (argc < 3)
	{
		cout << "Usage: mulmatrix.exe <first matrix file> <second matrix file>" << endl;
		return 1;
	}

	try 
	{
		auto mat1 = ReadMatrixFromFile(argv[1]);
		auto mat2 = ReadMatrixFromFile(argv[2]);
		cout << (mat1 * mat2) << endl;
	}
	catch (exception const& e)
	{
		cout << e.what() << endl;
		return 1;
	}

	return 0;
}