#pragma once
#include "SolidBody.h"

class CParallelepiped :	public CSolidBody
{
public:
	CParallelepiped(unsigned height, unsigned width, unsigned depth, unsigned density = 0);

	//virtual void SetDensity(unsigned density);
	virtual std::string ToString() const;

	unsigned GetHeight() const;
	void SetHeight(unsigned height);

	unsigned GetDepth() const;
	void SetDepth(unsigned depth);

	unsigned GetWidth() const;
	void SetWidth(unsigned width);

	virtual double GetVolume() const;
	virtual double GetWeight() const;

private:
	unsigned m_height;
	unsigned m_width;
	unsigned m_depth;
};

