#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cassert>

using namespace std;

class IsExtraSpace
{
private:
	char m_previousChar;
public:
	IsExtraSpace(char firstChar) : m_previousChar(firstChar) {}
	
	bool operator()(char readChar)
	{
		if (readChar != ' ')
		{
			m_previousChar = readChar;
			return false;
		}
		else if (m_previousChar == ' ')
		{
			return true;
		}
		else
		{
			m_previousChar = readChar;
			return false;
		}
	}
};

string RemoveExtraSpaces(string const& arg)
{
	string result = arg;
	if (result.empty())
	{
		return result;
	}

	auto fromIter = remove_if(result.begin(), result.end(), IsExtraSpace(result[0]));
	result.erase(fromIter, result.end());

	if (!result.empty() && result[result.size() - 1] == ' ')
	{
		result.erase(result.end() - 1);
	}

	return result;
}

void TestRemoveExtraSpaces()
{
	assert(RemoveExtraSpaces("   ") == "");
}

int main(int argc, char * argv[])
{
	TestRemoveExtraSpaces();

	cout << RemoveExtraSpaces("     Test    test     ") << '|' << endl;

	return 0;
}