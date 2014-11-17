#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cassert>

using namespace std;



vector<double> ReadVectorFromStream()
{
	double input;
	vector<double> doublesFromInput;
	
	while (cin >> input)
	{
		doublesFromInput.push_back(input);
	}

	return doublesFromInput;
}

void ProcessVector(vector<double>& input)
{
	if (input.empty())
	{
		return;
	}

	auto beginIter = input.begin();
	auto endIter = input.end();
    double minElement = *min_element(beginIter, endIter);
	transform(beginIter, endIter, beginIter, [minElement](double i){ return i * minElement; });
	sort(beginIter, endIter);
}

void PrintVector(const vector<double>& doubleVector )
{
	cout << setprecision(3);
	for (auto value : doubleVector)
	{
		cout << value << ' ';
	}
}

void TestProcessVector()
{
	vector<double> emptyVector;
	ProcessVector(emptyVector);
	assert(emptyVector.empty());

	double testArr1[] = { 0, 1, 2, 3, 4 };
	double resultArr1[] = { 0, 0, 0, 0, 0 };

	vector<double> testVector1(testArr1, testArr1 + sizeof(testArr1) / sizeof(double));
	ProcessVector(testVector1);
	assert(equal(testVector1.begin(), testVector1.end(), resultArr1));
}

int main(int argc, char * argv)
{
	TestProcessVector();


	vector<double> inputVector = ReadVectorFromStream();
	ProcessVector(inputVector);
	PrintVector(inputVector);

	return 0;
}