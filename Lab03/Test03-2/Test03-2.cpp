#include "stdafx.h"
#include "../Lab03-2/ProcessString.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(StringProcessingTest)

BOOST_AUTO_TEST_CASE(TestEmptyString)
{
	BOOST_CHECK(RemoveExtraSpaces("").empty());
}

BOOST_AUTO_TEST_CASE(TestOnlySpacesString)
{
	BOOST_CHECK(RemoveExtraSpaces("     ").empty());
}

BOOST_AUTO_TEST_CASE(TestFirstAndLastSpacesString)
{
	BOOST_CHECK_EQUAL(RemoveExtraSpaces(" a "), "a");
}

BOOST_AUTO_TEST_CASE(TestMiddleSpaces)
{
	BOOST_CHECK_EQUAL(RemoveExtraSpaces("a  a"), "a a");
}

BOOST_AUTO_TEST_CASE(TestSentenceWithoutExtraSpaces)
{
	BOOST_CHECK_EQUAL(RemoveExtraSpaces("Sentence wothout extra spaces!"), "Sentence wothout extra spaces!");
}

BOOST_AUTO_TEST_CASE(TestSentenceWithExtraSpaces)
{
	BOOST_CHECK_EQUAL(RemoveExtraSpaces(" Sentence with    extra    spaces! "), "Sentence with extra spaces!");
}

BOOST_AUTO_TEST_SUITE_END()
