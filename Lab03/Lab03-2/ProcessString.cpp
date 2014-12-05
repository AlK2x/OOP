#include "stdafx.h"
#include "ProcessString.h"

using namespace std;

void RemoveLastSpace(string & str)
{
	if (!str.empty() && str[str.size() - 1] == ' ')
	{
		str.erase(str.end() - 1);
	}
}

class DeleteExtraSpace
{
private:
	char m_previousChar;
public:
	DeleteExtraSpace(char firstChar) : m_previousChar(firstChar) {}

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

	auto fromIter = remove_if(result.begin(), result.end(), DeleteExtraSpace(result[0]));
	result.erase(fromIter, result.end());

	RemoveLastSpace(result);

	return result;
}
