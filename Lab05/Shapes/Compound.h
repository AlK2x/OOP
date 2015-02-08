#pragma once
#include "Body.h"
#include <vector>
#include <memory>

class CCompound : public CBody
{
public:
	typedef std::shared_ptr<CBody> pBody;

	CCompound();
	virtual std::string ToString() const;
	virtual double GetVolume() const;
	virtual double GetWeight() const;

	bool Add(const pBody& body);
	std::vector<pBody> GetObjects() const;

private:
	bool HasAddedObjectPointerToThis(const CCompound& body);

	std::vector<pBody> m_compound;
};

