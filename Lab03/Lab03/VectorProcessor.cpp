#include "stdafx.h"
#include "VectorProcessor.h"

using namespace std;

void ProcessVector(vector<double>& input)
{
	if (input.empty())
	{
		return;
	}

	auto beginIter = input.begin();
	auto endIter = input.end();
    double minElement = *min_element(beginIter, endIter);
	transform(beginIter, endIter, beginIter, [minElement](double i){
		return i * minElement; 
	});
	sort(beginIter, endIter);
}

vector<double> ReadVectorFromStream()
{
	istream_iterator<double> start(cin);
	istream_iterator<double> end;
	vector<double> doublesFromInput(start, end);

	return doublesFromInput;
}

void PrintVector(const vector<double>& doubleVector)
{
	ostream_iterator<double> outIt(cout, " ");
	copy(doubleVector.begin(), doubleVector.end(), outIt);
}