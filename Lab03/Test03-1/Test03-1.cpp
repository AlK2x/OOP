#include "stdafx.h"
#include "../Lab03/VectorProcessor.h"

using namespace std;



BOOST_AUTO_TEST_SUITE(VectorProcessingTest)

bool VerifyProcessVector(vector<double> input, vector<double> const& output)
{
	ProcessVector(input);
	return (input == output);
}

BOOST_AUTO_TEST_CASE(TestEmptyVector)
{
	BOOST_CHECK(VerifyProcessVector({}, {}));
	BOOST_CHECK(VerifyProcessVector({ 10 }, { 100 }));
	BOOST_CHECK(VerifyProcessVector({ -10 }, { 100 }));
	BOOST_CHECK(VerifyProcessVector({ 2, 3, 4 }, { 4, 6, 8 }));
	BOOST_CHECK(VerifyProcessVector({ -2, -3, -4 }, { 8, 12, 16 }));
	BOOST_CHECK(VerifyProcessVector({ 2, 3, 4, 0 }, { 0, 0, 0, 0 }));
	BOOST_CHECK(VerifyProcessVector({ -2, -3, -4, 0 }, { 0, 8, 12, 16 }));
}

BOOST_AUTO_TEST_SUITE_END()

