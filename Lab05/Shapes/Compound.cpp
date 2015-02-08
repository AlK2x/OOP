#include "stdafx.h"
#include "Compound.h"


CCompound::CCompound()
{
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