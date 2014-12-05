#include "stdafx.h"

using namespace std;

int main(int argc, char * argv)
{
	vector<double> inputVector = ReadVectorFromStream();
	ProcessVector(inputVector);
	PrintVector(inputVector);

	return 0;
}
