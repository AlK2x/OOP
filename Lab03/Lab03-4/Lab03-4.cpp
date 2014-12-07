#include "stdafx.h"
#include "PrimeGenerator.h"

using namespace std;

int main(int argc, char* argv[])
{
	int input;

	set<int> primeNumbers;
	while (cin >> input)
	{
		primeNumbers = GeneratePrimeNumersSet(input);

		PrintSet(primeNumbers);
		cout << endl;
		primeNumbers.clear();
	}

	return 0;
}