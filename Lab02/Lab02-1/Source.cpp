#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<int> FindStringOccurences(ifstream& ifs, string const& needle)
{
	vector<int> numLines;
	string line;
	int lineNum = 1;

	while (ifs.good())
	{
		getline(ifs, line);
		if (line.find(needle) != string::npos)
		{
			numLines.push_back(lineNum);
		}
		++lineNum;
	}

	return numLines;
}

int PrintResult(vector<int> const& numLines)
{
	int result = 0;
	if (numLines.empty())
	{
		result = 1;
		cout << "Text not found\n";
	}
	else
	{
		for (auto lineIndex : numLines)
		{
			cout << lineIndex << "\n";
		}
	}

	return result;
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Usage: findtext.exe <file name> <test to search>\n";
		return 1;
	}

	string filename = argv[1];
	string needle = argv[2];

	ifstream ifs(filename);
	if (ifs.is_open())
	{
		vector<int> numberLinesWithNeedle = FindStringOccurences(ifs, needle);
		return PrintResult(numberLinesWithNeedle);
	}
	else
	{
		cout << "Unable to open file: " << filename << "\n";
		return 1;
	}
}