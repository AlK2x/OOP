#include "stdafx.h"
#include "SolidBody.h"

CSolidBody::CSolidBody(unsigned density)
	:m_density(density)
{
}

void CSolidBody::SetDensity(unsigned density)
{
	m_density = density;
}

unsigned CSolidBody::GetDensity() const
{
	return m_density;
}