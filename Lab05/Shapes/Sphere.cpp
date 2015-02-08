#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "Sphere.h"


#include <cmath>

using namespace std;

CSphere::CSphere(unsigned radius, unsigned density)
	:m_radius(radius), CSolidBody(density)
{
}

string CSphere::ToString() const
{
	std::ostringstream strm;
	strm << "Sphere. Radius: " << m_radius
		 << " Density: " << m_density;
	return strm.str();
}

unsigned CSphere::GetRadius() const
{
	return m_radius;
}

void CSphere::SetRadius(unsigned radius)
{
	m_radius = radius;
}

double CSphere::GetVolume() const
{
	return 3.14 * pow(m_radius, 3) * 4 / 3;
}

double CSphere::GetWeight() const
{
	return GetVolume() * m_density;
}

bool CSphere::operator==(CSphere const& sp1)
{
	return m_radius == sp1.m_radius && m_density == sp1.m_density;
}