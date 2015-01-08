#include "stdafx.h"
#include "../RectangleShape/Rectangle.h"

BOOST_AUTO_TEST_SUITE(CreateRectangleTest)

BOOST_AUTO_TEST_CASE(TestCreateRectangle)
{
	CRectangle rect(1, 1, 10, 10);
	BOOST_CHECK_EQUAL(rect.GetWidth(), 10);
	BOOST_CHECK_EQUAL(rect.GetHeight(), 10);
	BOOST_CHECK_EQUAL(rect.GetLeft(), 1);
	BOOST_CHECK_EQUAL(rect.GetRight(), 11);
	BOOST_CHECK_EQUAL(rect.GetTop(), 1);
	BOOST_CHECK_EQUAL(rect.GetBottom(), 11);
	BOOST_CHECK_EQUAL(rect.GetArea(), 100);
	BOOST_CHECK_EQUAL(rect.GetPerimeter(), 40);
}

BOOST_AUTO_TEST_CASE(TestCreateRectangleWithNegativeWidth)
{
	CRectangle rect(1, 1, -5, 10);
	BOOST_CHECK_EQUAL(rect.GetWidth(), 0);
	BOOST_CHECK_EQUAL(rect.GetHeight(), 10);
	BOOST_CHECK_EQUAL(rect.GetLeft(), 1);
	BOOST_CHECK_EQUAL(rect.GetRight(), 1);
	BOOST_CHECK_EQUAL(rect.GetTop(), 1);
	BOOST_CHECK_EQUAL(rect.GetBottom(), 11);
	BOOST_CHECK_EQUAL(rect.GetArea(), 0);
	BOOST_CHECK_EQUAL(rect.GetPerimeter(), 20);
}

BOOST_AUTO_TEST_SUITE_END()

struct TestRectangleFixture
{
	CRectangle rect = CRectangle(1, 2, 10, 20);
};

BOOST_FIXTURE_TEST_SUITE(TestRectangle, TestRectangleFixture)

BOOST_AUTO_TEST_CASE(TestSetWidth)
{
	BOOST_CHECK_EQUAL(rect.GetWidth(), 10);
	BOOST_CHECK_EQUAL(rect.GetRight(), 11);
	rect.SetWidth(12);
	BOOST_CHECK_EQUAL(rect.GetWidth(), 12);
	BOOST_CHECK_EQUAL(rect.GetRight(), 13);
	rect.SetWidth(-10);
	BOOST_CHECK_EQUAL(rect.GetWidth(), 0);
	BOOST_CHECK_EQUAL(rect.GetRight(), 1);
}

BOOST_AUTO_TEST_CASE(TestSetHeight)
{
	BOOST_CHECK_EQUAL(rect.GetHeight(), 20);
	rect.SetHeight(12);
	BOOST_CHECK_EQUAL(rect.GetHeight(), 12);
	BOOST_CHECK_EQUAL(rect.GetBottom(), 14);
	rect.SetHeight(-10);
	BOOST_CHECK_EQUAL(rect.GetHeight(), 0);
	BOOST_CHECK_EQUAL(rect.GetBottom(), 2);
}

BOOST_AUTO_TEST_CASE(TestSetTop)
{
	BOOST_CHECK_EQUAL(rect.GetTop(), 2);
	rect.SetTop(42);
	BOOST_CHECK_EQUAL(rect.GetTop(), 42);
	BOOST_CHECK_EQUAL(rect.GetBottom(), 62);
}

BOOST_AUTO_TEST_CASE(TestSetLeft)
{
	BOOST_CHECK_EQUAL(rect.GetLeft(), 1);
	rect.SetLeft(42);
	BOOST_CHECK_EQUAL(rect.GetLeft(), 42);
	BOOST_CHECK_EQUAL(rect.GetRight(), 52);
}

BOOST_AUTO_TEST_CASE(TestSetRight)
{
	BOOST_CHECK_EQUAL(rect.GetRight(), 11);
	rect.SetRight(42);
	BOOST_CHECK_EQUAL(rect.GetRight(), 42);
	BOOST_CHECK_EQUAL(rect.GetLeft(), 32);
}

BOOST_AUTO_TEST_CASE(TestSetBottom)
{
	BOOST_CHECK_EQUAL(rect.GetBottom(), 22);
	rect.SetBottom(42);
	BOOST_CHECK_EQUAL(rect.GetBottom(), 42);
	BOOST_CHECK_EQUAL(rect.GetTop(), 22);
}

BOOST_AUTO_TEST_CASE(TestMoveRectangle)
{
	rect.Move(4, 3);
	BOOST_CHECK_EQUAL(rect.GetLeft(), 5);
	BOOST_CHECK_EQUAL(rect.GetTop(), 5);
	BOOST_CHECK_EQUAL(rect.GetRight(), 15);
	BOOST_CHECK_EQUAL(rect.GetBottom(), 25);
}

BOOST_AUTO_TEST_CASE(TestMoveToNegativeRectangle)
{
	rect.Move(-6, -7);
	BOOST_CHECK_EQUAL(rect.GetLeft(), -5);
	BOOST_CHECK_EQUAL(rect.GetTop(), -5);
	BOOST_CHECK_EQUAL(rect.GetRight(), 5);
	BOOST_CHECK_EQUAL(rect.GetBottom(), 15);
}

BOOST_AUTO_TEST_CASE(TestScaleRectangle)
{
	rect.Scale(2, 5);
	BOOST_CHECK_EQUAL(rect.GetLeft(), 1);
	BOOST_CHECK_EQUAL(rect.GetTop(), 2);
	BOOST_CHECK_EQUAL(rect.GetWidth(), 5);
	BOOST_CHECK_EQUAL(rect.GetHeight(), 4);
	BOOST_CHECK_EQUAL(rect.GetRight(), 6);
	BOOST_CHECK_EQUAL(rect.GetBottom(), 6);
}

BOOST_AUTO_TEST_CASE(TestNegativeScaleRectangle)
{
	rect.Scale(-2, -5);
	BOOST_CHECK_EQUAL(rect.GetLeft(), 1);
	BOOST_CHECK_EQUAL(rect.GetTop(), 2);
	BOOST_CHECK_EQUAL(rect.GetWidth(), 10);
	BOOST_CHECK_EQUAL(rect.GetHeight(), 20);
	BOOST_CHECK_EQUAL(rect.GetRight(), 11);
	BOOST_CHECK_EQUAL(rect.GetBottom(), 22);
}

BOOST_AUTO_TEST_SUITE_END()

struct TestIntersectRectangleFixture
{
	CRectangle rect1 = CRectangle(1, 1, 10, 10);
	CRectangle rect2 = CRectangle(11, 12, 1, 1);
};

BOOST_FIXTURE_TEST_SUITE(TestIntersectRectangle, TestIntersectRectangleFixture)

BOOST_AUTO_TEST_CASE(TestNonIntersectRectangle)
{
	BOOST_CHECK(!rect1.Intersect(rect2));
}

BOOST_AUTO_TEST_SUITE_END();