#pragma once

#include <sstream>
#include <string>
#include <memory>



class CBody
{
public:
	typedef std::shared_ptr<CBody> pBody;

	virtual std::string ToString() const = 0;
	virtual double GetVolume() const = 0;
	virtual double GetWeight() const;
	virtual unsigned GetDensity() const = 0;

	virtual ~CBody();
};
