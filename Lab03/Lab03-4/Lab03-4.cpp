#include "stdafx.h"
#include "PrimeGenerator.h"

using namespace std;

int main(int argc, char* argv[])
{
	int input;

	set<unsigned> primeNumbers;
	while (cin >> input)
	{
		primeNumbers = GeneratePrimeNumersSet(input);

		ostream_iterator<double> outIt(cout, " ");
		copy(primeNumbers.begin(), primeNumbers.end(), outIt);

		primeNumbers.clear();
	}

	return 0;
}