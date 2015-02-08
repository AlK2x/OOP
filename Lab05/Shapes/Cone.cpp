#include "stdafx.h"
#include "Cone.h"


CCone::CCone(unsigned radius, unsigned height, unsigned density)
	: m_radius(radius), m_height(height), CSolidBody(density)
{
}

double CCone::GetVolume() const
{
	return 3.14 * m_radius * m_radius * m_height / 3;
}

double CCone::GetWeight() const
{
	return GetVolume() * m_density;
}

std::string CCone::ToString() const
{
	std::stringstream ss;
	ss << "Cone. Radius: " << m_radius << " Density: " << m_density;
	return ss.str();
}

unsigned CCone::GetRadius() const
{
	return m_radius;
}

unsigned CCone::GetHeight() const
{
	return m_height;
}

void CCone::SetRadius(unsigned radius)
{
	m_radius = radius;
}

void CCone::SetHeight(unsigned height)
{
	m_height = height;
}