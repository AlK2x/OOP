#include "stdafx.h"
#include "../Shapes/Sphere.h"
#include <cmath>
#define _USE_MATH_DEFINES



struct SphereFixture
{
	CSphere s = CSphere(3, 10);
	const CBody & sAsBody = s;
};

BOOST_FIXTURE_TEST_SUITE(Sphere, SphereFixture)

BOOST_AUTO_TEST_CASE(RadiusPassedToConstructor)
{
	BOOST_CHECK_EQUAL(s.GetRadius(), 3);
	BOOST_CHECK_EQUAL(sAsBody.GetVolume(), 3.14 * 36 );
	BOOST_CHECK_EQUAL(sAsBody.ToString(), "Sphere. Radius: 3 Density: 10");
	BOOST_CHECK_EQUAL(sAsBody.GetWeight(), 3.14 * 36 * 10);
}

BOOST_AUTO_TEST_CASE(CompareTwoSperes)
{
	CSphere s1(2, 2);
	CSphere s2(2, 2);
	BOOST_CHECK(s1 == s2);
}

BOOST_AUTO_TEST_CASE(ChangeRadius)
{
	s.SetRadius(6);
	BOOST_CHECK(s == CSphere(6, 10));
}

BOOST_AUTO_TEST_CASE(ChangeDensity)
{
	s.SetDensity(13);
	BOOST_CHECK(s == CSphere(3, 13));
}

BOOST_AUTO_TEST_SUITE_END()