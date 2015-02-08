#include "stdafx.h"
#include "Point.h"

CPoint::CPoint() : CPoint(0, 0) { }

CPoint::CPoint(double x, double y) : m_x(x), m_y(y) { }

double CPoint::GetX() const
{
	return m_x;
}

double CPoint::GetY() const
{
	return m_y;
}

double CPoint::GetPerimeter() const
{
	return 0.0;
}

double CPoint::GetArea() const
{
	return 0.0;
}

std::string CPoint::ToString() const
{
	std::ostringstream strm;
	strm << "point " << m_x << " " << m_y;
	return strm.str();
}