#include "stdafx.h"
#include "../Shapes/Cone.h"

struct ConeFixture
{
	CCone cone = CCone(3, 5);
	const CBody & asBody = cone;
	const CSolidBody & asSolid = cone;
};

BOOST_FIXTURE_TEST_SUITE(ConeTest, ConeFixture)

BOOST_AUTO_TEST_CASE(CreateCone)
{
	BOOST_CHECK_EQUAL(cone.GetHeight(), 5);
	BOOST_CHECK_EQUAL(cone.GetRadius(), 3);
	BOOST_CHECK_EQUAL(asSolid.GetDensity(), 0);
	BOOST_CHECK_EQUAL(asBody.GetVolume(), 3.14 * 3 * 3 * 5 / 3);
	BOOST_CHECK_EQUAL(asBody.GetWeight(), 0);
}

BOOST_AUTO_TEST_SUITE_END()