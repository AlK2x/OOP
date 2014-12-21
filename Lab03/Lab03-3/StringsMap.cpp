#include "stdafx.h"
#include "StringsMap.h"

using namespace std;

void PrintWordFriquency(stringMap wordsMap)
{
	for (auto const& wordPair : wordsMap)
	{
		cout << wordPair.first << "->" << wordPair.second << endl;
	}
}

map<string, int> ReadStringsFromStream(istream& ist)
{
	stringMap wordsFriquencyMap;
	string inputString;
	while (ist >> inputString)
	{
		transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
		++wordsFriquencyMap[inputString];
	}

	return wordsFriquencyMap;
}