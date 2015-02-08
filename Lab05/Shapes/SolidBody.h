#pragma once
#include "Body.h"
class CSolidBody : public CBody
{
public:

	virtual void SetDensity(unsigned density);
	virtual unsigned GetDensity() const;

protected:
	CSolidBody(unsigned density);

	unsigned m_density;
};
