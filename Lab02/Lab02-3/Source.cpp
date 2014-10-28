#include <iostream>
#include <string>
#include <fstream>
#include "matrix.h"

using namespace std;

int main(int argc, char * argv[])
{
	if (argc < 3)
	{
		cout << "Usage: mulmatrix.exe <first matrix file> <second matrix file>\n";
		return 1;
	}

	string filename1 = argv[1];
	string filename2 = argv[2];
	ifstream ifs1(filename1);
	ifstream ifs2(filename2);

	if (!ifs1.is_open())
	{
		cout << "Unable to open file: " << filename1 << "\n";
		return 1;
	}
	else if (!ifs2.is_open())
	{
		cout << "Unable to open file: " << filename2 << "\n";
		return 1;
	}
	else
	{
		try 
		{
			Matrix3x3 firstMatrix, secondMatrix;
			firstMatrix.ReadFromFile(ifs1);
			secondMatrix.ReadFromFile(ifs2);
			cout << firstMatrix * secondMatrix << "\n";
		}
		catch (ReadMatrix3x3Exception)
		{
			cout << "Read matrix from file exception.\n";
			return 1;
		}
	}

	return 0;
}