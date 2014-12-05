#include "stdafx.h"
#include "../Lab03-2/ProcessString.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(StringProcessingTest)

BOOST_AUTO_TEST_CASE(TestEmptyString)
{
	string empty("");
	string result = RemoveExtraSpaces(empty);
	BOOST_CHECK(result.empty());
}

BOOST_AUTO_TEST_CASE(TestOnlySpacesString)
{
	string spaces("     ");
	string result = RemoveExtraSpaces(spaces);
	BOOST_CHECK(result.empty());
}

BOOST_AUTO_TEST_CASE(TestFirstAndLastSpacesString)
{
	string fsString(" a ");
	string result = RemoveExtraSpaces(fsString);
	BOOST_CHECK_EQUAL("a", result);
}

BOOST_AUTO_TEST_CASE(TestMiddleSpaces)
{
	string fsString("a  a");
	string result = RemoveExtraSpaces(fsString);
	BOOST_CHECK_EQUAL("a a", result);
}

BOOST_AUTO_TEST_SUITE_END()
