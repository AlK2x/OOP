#include "stdafx.h"
#include "../Lab03-3/StringsMap.h"

using namespace std;

bool CompareStringsFriquencyMaps(stringMap input, stringMap reference)
{
	return input == reference;
}

struct InitializeStringMap
{
	stringMap reference;
};

BOOST_FIXTURE_TEST_SUITE(TestMapWithString, InitializeStringMap)

BOOST_AUTO_TEST_CASE(TestEmptyStream)
{
	BOOST_CHECK(ReadStringsFromStream(stringstream("")).empty());
}

BOOST_AUTO_TEST_CASE(TestNotRepeatingOneWord)
{
	reference["one"] = 1;
	BOOST_CHECK( CompareStringsFriquencyMaps(ReadStringsFromStream(stringstream("one")), reference ));
}

BOOST_AUTO_TEST_CASE(TestRepeatingOneWord)
{
	reference["two"] = 2;
	BOOST_CHECK(CompareStringsFriquencyMaps(ReadStringsFromStream(stringstream("two two")), reference));
}

BOOST_AUTO_TEST_CASE(TestMultipleNonRepeatingWords)
{
	reference["first"] = 1;
	reference["second"] = 1;
	reference["third"] = 1;
	BOOST_CHECK(CompareStringsFriquencyMaps(ReadStringsFromStream(stringstream("first second third")), reference));
}

BOOST_AUTO_TEST_CASE(TestMultipleRepeatingWords)
{
	reference["first"] = 2;
	reference["second"] = 1;
	reference["third"] = 2;
	BOOST_CHECK(CompareStringsFriquencyMaps(ReadStringsFromStream(stringstream("third first  first second third")), reference));
}

BOOST_AUTO_TEST_CASE(TestMultipleRepeatingWordsWithDifferentRegister)
{
	reference["first"] = 2;
	reference["second"] = 1;
	reference["third"] = 2;
	BOOST_CHECK(CompareStringsFriquencyMaps(ReadStringsFromStream(stringstream("thiRd First  fiRSt seCond THIRD")), reference));
}

BOOST_AUTO_TEST_SUITE_END()