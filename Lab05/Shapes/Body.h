#pragma once

#include <sstream>
#include <string>

class CBody
{
public:
	virtual std::string ToString() const = 0;
	virtual double GetVolume() const = 0;
	virtual double GetWeight() const = 0;
};
