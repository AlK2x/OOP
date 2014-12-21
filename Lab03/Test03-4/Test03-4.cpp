#include "stdafx.h"
#include "../Lab03-4/PrimeGenerator.h"
#include <vector>

using namespace std;

bool CheckPrimeNumbers(int bound, vector<int> prepearedNumbers)
{
	set<int> reference;
	reference.insert(prepearedNumbers.begin(), prepearedNumbers.end());
	return GeneratePrimeNumersSet(bound) == reference;
}

BOOST_AUTO_TEST_SUITE(PrimeGeneratorTest)

BOOST_AUTO_TEST_CASE(TestLowBoundWithoutPrimeNumbers)
{
	BOOST_CHECK(CheckPrimeNumbers(-1, {}));
	BOOST_CHECK(CheckPrimeNumbers(0, {}));
	BOOST_CHECK(CheckPrimeNumbers(1, {}));
}

BOOST_AUTO_TEST_CASE(TestPrimeSetsTo2)
{
	BOOST_CHECK(CheckPrimeNumbers(2, { 2 }));
}

BOOST_AUTO_TEST_CASE(TestPrimeSetsTo3)
{
	BOOST_CHECK(CheckPrimeNumbers(3, { 2, 3 }));
}

BOOST_AUTO_TEST_CASE(TestPrimeSetsTo4)
{
	BOOST_CHECK(CheckPrimeNumbers(4, { 2, 3 }));
}

BOOST_AUTO_TEST_CASE(TestPrimeSetsTo5)
{
	BOOST_CHECK(CheckPrimeNumbers(5, { 2, 3, 5 }));
}

BOOST_AUTO_TEST_CASE(TestPrimeSets)
{
	BOOST_CHECK(CheckPrimeNumbers(6, { 2, 3, 5 }));
	BOOST_CHECK(CheckPrimeNumbers(7, { 2, 3, 5, 7 }));
	BOOST_CHECK(CheckPrimeNumbers(8, { 2, 3, 5, 7 }));
	BOOST_CHECK(CheckPrimeNumbers(9, { 2, 3, 5, 7 }));
	BOOST_CHECK(CheckPrimeNumbers(10, { 2, 3, 5, 7 }));
	BOOST_CHECK(CheckPrimeNumbers(11, { 2, 3, 5, 7, 11 }));
}

BOOST_AUTO_TEST_SUITE_END()