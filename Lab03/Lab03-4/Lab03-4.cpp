#include "stdafx.h"
#include "PrimeGenerator.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int input;

	set<int> primeNumbers;
	while (cin >> input)
	{
		primeNumbers = GeneratePrimeNumersSet(input);

		cout << "calc ok";
		cout << '\n';

		//ostream_iterator<double> outIt(cout, " ");
		//copy(primeNumbers.begin(), primeNumbers.end(), outIt);

		//primeNumbers.clear();
	}

	return 0;
}