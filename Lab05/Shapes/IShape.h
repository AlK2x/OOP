#pragma once
#include <string>
class IShape
{
public:
	virtual double GetPerimeter()const = 0;
	virtual double GetArea()const = 0;
	virtual std::string ToString() const = 0;

	virtual ~IShape() {}
};

