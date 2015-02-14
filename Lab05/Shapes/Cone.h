#pragma once
#include "SolidBody.h"
class CCone :
	public CSolidBody
{
public:
	CCone(unsigned radius, unsigned height, unsigned density = 0);
	
	virtual std::string ToString() const;
	virtual double GetVolume() const;

	unsigned GetRadius() const;
	unsigned GetHeight() const;

	void SetRadius(unsigned radius);
	void SetHeight(unsigned height);

private:
	unsigned m_radius;
	unsigned m_height;
};

