#include "stdafx.h"
#include "Compound.h"


CCompound::CCompound()
{
}

std::string CCompound::ToString() const
{
	std::stringstream ss;
	ss << "";
	return ss.str();
}

double CCompound::GetVolume() const
{
	double volume = 0;

	for (auto& body : m_compound)
	{
		volume += body->GetVolume();
	}

	return volume;
}

double CCompound::GetWeight() const
{
	double weight = 0;

	for (auto& body : m_compound)
	{
		weight += body->GetVolume();
	}

	return weight;
}

bool CCompound::Add(const pBody& body)
{
	CCompound * comp = dynamic_cast<CCompound*>(&*body);
	if (comp != 0)
	{
		if (HasAddedObjectPointerToThis(*comp))
		{
			return false;
		}
	}

	m_compound.push_back(CCompound::pBody(body));
	return true;
}

std::vector<CCompound::pBody> CCompound::GetObjects() const
{
	return m_compound;
}

bool CCompound::HasAddedObjectPointerToThis(const CCompound& compound)
{
	if (std::addressof(compound) == this)
	{
		return true;
	}

	CCompound* comp;

	for (auto& obj : compound.GetObjects())
	{
		comp = dynamic_cast<CCompound*>(&*obj);
		if (comp != 0)
		{
			bool answer = HasAddedObjectPointerToThis(*comp);
			if (answer)
			{
				return answer;
			}
		}
	}

	return false;
}