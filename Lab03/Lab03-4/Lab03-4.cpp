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
		primeNumbers.clear();
	}

	return 0;
}