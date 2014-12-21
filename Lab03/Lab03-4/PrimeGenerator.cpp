#include "stdafx.h"
#include "PrimeGenerator.h"

using namespace std;

//bool IsPrime(unsigned number)
//{
//	if (number < 2)
//	{
//		return false;
//	}
//	else if (number < 4)
//	{
//		return true;
//	}
//
//	unsigned i = 2;
//	while (i * i < number)
//	{
//		if (number % i == 0)
//		{
//			return false;
//		}
//		++i;
//	}
//
//	return true;
//}

set<int> GeneratePrimeNumersSet(int upperBound)
{
	set<int> primeNumbers;
	if (upperBound < 2)
	{
		return primeNumbers;
	}

	vector<bool> primeVector(upperBound + 1, true);
	const int sqrtBound = static_cast<int>(sqrt(upperBound));
	for (int n = 2; n <= sqrtBound; ++n)
	{
		if (primeVector[n])
		{
			for (unsigned k = n * n, ulim = static_cast<unsigned>(upperBound); k <= ulim; k += n)
			{
				primeVector[k] = false;
			}
		}
	}

	for (size_t i = 2; i < primeVector.size(); ++i)
	{
		if (primeVector[i])
		{
			primeNumbers.insert(i);
		}
	}

	return primeNumbers;
}