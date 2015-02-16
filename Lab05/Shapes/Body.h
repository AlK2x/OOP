#pragma once

#include <sstream>
#include <string>
#include <memory>
#include <iostream>


class CBody
{
public:
	typedef std::shared_ptr<CBody> pBody;

	CBody() { std::cout << "Body created\n"; }

	virtual std::string ToString() const = 0;
	virtual double GetVolume() const = 0;
	virtual double GetWeight() const;
	virtual unsigned GetDensity() const = 0;

	virtual ~CBody();
};
