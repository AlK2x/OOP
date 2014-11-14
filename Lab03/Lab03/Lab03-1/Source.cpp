#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

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

int main(int argc, char * argv)
{
	vector<double> inputVector = ReadVectorFromStream();
	ProcessVector(inputVector);
	PrintVector(inputVector);

	return 0;
}