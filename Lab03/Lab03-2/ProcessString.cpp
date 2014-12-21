#include "stdafx.h"
#include "ProcessString.h"

using namespace std;

class DeleteExtraSpace
{
private:
	char m_previousChar;
public:
	DeleteExtraSpace() : m_previousChar(' ') {}

	bool operator()(char readChar)
	{
		if (readChar == ' ' && m_previousChar == ' ')
		{
			return true;
		}

		m_previousChar = readChar;
		return false;
	}
};

string RemoveExtraSpaces(string const& arg)
{
	string result = arg;

	auto fromIter = remove_if(result.begin(), result.end(), DeleteExtraSpace());
	result.erase(fromIter, result.end());

	if (!result.empty() && result.back() == ' ')
	{
		result.pop_back();
	}

	return result;
}
