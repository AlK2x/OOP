#include "stdafx.h"
#include "Body.h"

double CBody::GetWeight() const
{
	return GetVolume() * GetDensity();
}

CBody::~CBody() {}