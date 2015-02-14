#include "stdafx.h"
#include "../Shapes/Compound.h"
#include "../Shapes/Cone.h"
#include "../Shapes/Parallelepiped.h"
#include "../Shapes/Cylinder.h"

struct CompoundFixture
{

};

BOOST_FIXTURE_TEST_SUITE(CompoundBodyTest, CompoundFixture)

BOOST_AUTO_TEST_CASE(AddCompsiteToComposite)
{
	CCompound * compound = new CCompound();
	CCompound::pBody co(new CCone(10, 10, 10));
	CCompound::pBody cy(new CCylinder(10, 10, 10));

	BOOST_CHECK(compound->Add(co));
	BOOST_CHECK(compound->Add(cy));
	CCompound::pBody comp(compound);
	BOOST_CHECK(!compound->Add(comp));
}

BOOST_AUTO_TEST_SUITE_END()