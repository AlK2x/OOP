#include "stdafx.h"
#include "PrimeGenerator.h"
#include <chrono>
#include <string>

using namespace std;


set<unsigned> GeneratePrimeNumersSet(int upperBound)
{
	set<unsigned> primeNumbers;
	if (upperBound < 2)
	{
		return primeNumbers;
	}

	vector<bool> primeVector(upperBound + 1, true);
	const unsigned sqrtBound = sqrt(upperBound);
	cout << sqrtBound << endl;
	for (unsigned n = 2; n <= sqrtBound; ++n)
	{
		if (primeVector[n])
		{
			unsigned ulim = upperBound;
			for (unsigned k = n * n; k <= ulim; k += n)
			{
				primeVector[k] = false;
			}
		}
	}

	for (unsigned i = 2; i < primeVector.size(); ++i)
	{
		if (primeVector[i])
		{
			primeNumbers.insert(i);
		}
	}

	return primeNumbers;
}