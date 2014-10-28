#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void FindStringOccurences(ifstream& ifs, string const& needle, vector<int>& numLines)
{
	string line;
	int lineNum = 1;
	try
	{
		while (getline(ifs, line))
		{
			if (line.find(needle) != string::npos)
			{
				numLines.push_back(lineNum);
			}
			++lineNum;
		}
	}
	catch (ios_base::failure& e)
	{
		cout << "Read file exception. Error: " << e.what() << "\n"
			<< "Code :" << e.code() << "\n";
	}
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
		for (size_t i = 0; i < numLines.size(); ++i)
		{
			cout << numLines[i] << "\n";
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
		vector<int> numberLinesWithNeedle;
		FindStringOccurences(ifs, needle, numberLinesWithNeedle);
		PrintResult(numberLinesWithNeedle);
	}
	else
	{
		cout << "Unable to open file: " << filename << "\n";
		return 1;
	}

	return 0;
}