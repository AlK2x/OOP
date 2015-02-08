#pragma once
#include "IShape.h"
class CLineSegment 
{
public:
	CLineSegment();
	~CLineSegment();

	virtual double GetArea() const;
	virtual double GetPerimeter() const;
	virtual std::string ToString() const;
};

