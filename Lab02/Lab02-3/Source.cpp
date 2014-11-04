#include "matrix.h"

using namespace std;

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