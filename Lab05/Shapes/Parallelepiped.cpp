#include "stdafx.h"
#include "Parallelepiped.h"


CParallelepiped::CParallelepiped(unsigned height, unsigned width, unsigned depth, unsigned density)
	:m_height(height), m_width(width), m_depth(depth), CSolidBody(density)
{
}

unsigned CParallelepiped::GetHeight() const
{
	return m_height;
}

void CParallelepiped::SetHeight(unsigned height)
{
	m_height = height;
}

unsigned CParallelepiped::GetWidth() const
{
	return m_width;
}

void CParallelepiped::SetDepth(unsigned depth)
{
	m_depth = depth;
}

unsigned CParallelepiped::GetDepth() const
{
	return m_depth;
}

void CParallelepiped::SetWidth(unsigned width)
{
	m_width = width;
}

double CParallelepiped::GetVolume() const
{
	return m_depth * m_height * m_width;
}

double CParallelepiped::GetWeight() const
{
	return GetVolume() * m_density;
}

std::string CParallelepiped::ToString() const
{
	std::stringstream ss;
	ss << "Parallelepiped. [" << m_height << "x" << m_width << "x" << m_depth << "] Density: "
		<< m_density;
	return ss.str();
}