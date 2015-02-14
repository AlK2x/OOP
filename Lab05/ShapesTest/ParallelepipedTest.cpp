#include "stdafx.h"
#include "../Shapes/Parallelepiped.h"

bool CompareParallelepipedState(CParallelepiped const & p1, CParallelepiped const & p2)
{
	return p1.GetHeight() == p2.GetHeight() &&
		p1.GetDepth() == p2.GetDepth() &&
		p1.GetDensity() == p2.GetDensity();
}

struct ParallelepipedFixture
{
	CParallelepiped p = CParallelepiped(1, 2, 3);
	const CBody & asBody = p;
	const CSolidBody & asSolid = p;
};

BOOST_FIXTURE_TEST_SUITE(Parallelepiped, ParallelepipedFixture)

BOOST_AUTO_TEST_CASE(CreateParallelepiped)
{
	BOOST_CHECK_EQUAL(p.GetHeight(), 1);
	BOOST_CHECK_EQUAL(p.GetWidth(), 2);
	BOOST_CHECK_EQUAL(p.GetDepth(), 3);
}

BOOST_AUTO_TEST_CASE(ChangeHeight)
{
	p.SetHeight(10);
	BOOST_CHECK(CompareParallelepipedState(p, CParallelepiped(10, 2, 3)));
	p.SetDepth(10);
	BOOST_CHECK(CompareParallelepipedState(p, CParallelepiped(10, 3, 10)));
	p.SetWidth(10);
	BOOST_CHECK(CompareParallelepipedState(p, CParallelepiped(10, 10, 10)));
}

BOOST_AUTO_TEST_CASE(ParallelepipedGetters)
{
	BOOST_CHECK_EQUAL(asBody.GetVolume(), 6);
	p.SetDensity(10);
	BOOST_CHECK_EQUAL(asBody.GetWeight(), 60);
}

BOOST_AUTO_TEST_SUITE_END()