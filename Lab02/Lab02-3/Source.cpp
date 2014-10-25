#include <iostream>
#include <string>
#include <fstream>
#include "matrix.h"

using namespace std;

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		cout << "Usage: invert.exe <matrix file>\n";
		return 1;
	}

	string filename = argv[1];
	ifstream ifs(filename);
	if (ifs.is_open())
	{

	}
	else
	{
		cout << "Unable to open file: " << filename << "\n";
		return 1;
	}

	Matrix3x3 matrix;
	matrix.ReadFromFile(ifs);
	cout << matrix;

	return 0;
}