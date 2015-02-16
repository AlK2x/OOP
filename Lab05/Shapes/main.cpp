#include "stdafx.h"
#include "Body.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const double G = 9.18;
const double P = 1000;

CBody::pBody CreateSphere(istream & ist);
CBody::pBody CreateParallelepiped(istream & ist);
CBody::pBody CreateCone(istream & ist);
CBody::pBody CreateCylinder(istream & ist);
CBody::pBody CreateComound(istream & ist);

CBody::pBody ReadShape(istream & ist)
{
	string command;
	ist >> command;

	if (command == "sphere")
	{
		return CreateSphere(ist);
	}
	else if (command == "parallelepiped")
	{
		return CreateParallelepiped(ist);
	}
	else if (command == "cone")
	{
		return CreateCone(ist);
	}
	else if (command == "cylinder")
	{
		return CreateCylinder(ist);
	}
	else if (command == "compound")
	{
		return CreateComound(ist);
	}
	else
	{
		return nullptr;
	}
}

CBody::pBody CreateSphere(istream & ist)
{
	unsigned radius, density;
	ist >> radius >> density;

	return CBody::pBody(new CSphere(radius, density));
}

CBody::pBody CreateParallelepiped(istream & ist)
{
	unsigned height, width, depth, density;
	ist >> height >> width >> depth >> density;

	return CBody::pBody(new CParallelepiped(height, width, depth, density));
}

CBody::pBody CreateCone(istream & ist)
{
	unsigned radius, height, density;
	ist >> radius >> height >> density;

	return CBody::pBody(new CCone(radius, height, density));
}

CBody::pBody CreateCylinder(istream & ist)
{
	unsigned radius, height, density;
	ist >> radius >> height >> density;

	return CBody::pBody(new CCylinder(radius, height, density));
}

CBody::pBody CreateComound(istream & ist)
{
	CCompound * compound = new CCompound();

	CBody::pBody shape = ReadShape(ist);
	while (shape != nullptr)
	{
		compound->Add(shape);
		shape = ReadShape(ist);
	} 

	return CBody::pBody(compound);
}

bool CompareWeight(CBody::pBody shape1, CBody::pBody shape2)
{
	return shape1->GetWeight() < shape2->GetWeight();
}

bool CompareWeightInWater(CBody::pBody shape1, CBody::pBody shape2)
{
	double p1, p2;
	p1 = (shape1->GetDensity() - P) * G * shape1->GetVolume();
	p2 = (shape2->GetDensity() - P) * G * shape2->GetVolume();
	return p1 < p2;
}

int main(int argc, char * argv[])
{
	vector<CBody::pBody> shapes;
	CBody::pBody shape = ReadShape(cin);

	while (shape != nullptr)
	{
		shapes.push_back(shape);
		shape = ReadShape(cin);
	}

	cout << "Ok. computing ... " << '\n';

	if (!shapes.empty())
	{
		auto maxWeightBody = max_element(shapes.begin(), shapes.end(), CompareWeight);
		auto maxWeightInWater = max_element(shapes.begin(), shapes.end(), CompareWeightInWater);

		cout << "Body with max weight: " << (*maxWeightBody)->ToString() << '\n';
		cout << "Body with max weight in water: " << (*maxWeightInWater)->ToString() << '\n';
	}
	else
	{
		cout << "There are no shapes\n";
	}
	

	return 0;
}