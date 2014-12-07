#include "stdafx.h"
#include "../Lab03-4/PrimeGenerator.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(PrimeGeneratorTest)

bool TestPrimeGenerator(int bound, set<int> reference)
{
	set<int> result = GeneratePrimeNumersSet(bound);
	return result == reference;
}

BOOST_AUTO_TEST_CASE(AllTests)
{
	BOOST_CHECK(TestPrimeGenerator(0, {}));
	BOOST_CHECK(TestPrimeGenerator(1, {}));
	BOOST_CHECK(TestPrimeGenerator(-1, {}));
	BOOST_CHECK(TestPrimeGenerator(2, { 2 }));
	BOOST_CHECK(TestPrimeGenerator(3, { 2, 3}));
	BOOST_CHECK(TestPrimeGenerator(4, { 2, 3 }));
	BOOST_CHECK(TestPrimeGenerator(5, { 2, 3, 5}));
	BOOST_CHECK(TestPrimeGenerator(6, { 2, 3, 5}));
	BOOST_CHECK(TestPrimeGenerator(7, { 2, 3, 5, 7 }));
	BOOST_CHECK(TestPrimeGenerator(8, { 2, 3, 5, 7 }));
	BOOST_CHECK(TestPrimeGenerator(9, { 2, 3, 5, 7 }));
	BOOST_CHECK(TestPrimeGenerator(10, { 2, 3, 5, 7 }));
	BOOST_CHECK(TestPrimeGenerator(11, { 2, 3, 5, 7, 11 }));
}

BOOST_AUTO_TEST_SUITE_END()