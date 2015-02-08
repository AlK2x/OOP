#include "stdafx.h"
#include "Cylinder.h"


CCylinder::CCylinder(unsigned radius, unsigned height, unsigned density)
	: m_radius(radius), m_height(height), CSolidBody(density)
{
}

double CCylinder::GetVolume() const
{
	return 3.14 * m_radius * m_radius * m_height / 3;
}

double CCylinder::GetWeight() const
{
	return GetVolume() * m_density;
}

std::string CCylinder::ToString() const
{
	std::stringstream ss;
	ss << "Cylinder. Radius: " << m_radius << " Density: " << m_density;
	return ss.str();
}

unsigned CCylinder::GetRadius() const
{
	return m_radius;
}

unsigned CCylinder::GetHeight() const
{
	return m_height;
}

void CCylinder::SetRadius(unsigned radius)
{
	m_radius = radius;
}

void CCylinder::SetHeight(unsigned height)
{
	m_height = height;
}