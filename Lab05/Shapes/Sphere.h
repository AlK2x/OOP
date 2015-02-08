#pragma once
#include "SolidBody.h"

class CSphere :	public CSolidBody
{
public:
	CSphere(unsigned radius, unsigned density);

	virtual std::string ToString() const;
	virtual double GetVolume() const;
	virtual double GetWeight() const;

	unsigned GetRadius() const;
	void SetRadius(unsigned radius);

	bool operator==(CSphere const& sp1);

private:

	unsigned m_radius;
};

bool operator==(CSphere const& sp1, CSphere const& sp2);