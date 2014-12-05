#include "stdafx.h"

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cassert>

using namespace std;

map<string, int> ReadStringsFromStream(istream& ist)
{
	map<string, int> wordsFriquencyMap;
	string inputString;
	while (ist >> inputString)
	{
		transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
		++wordsFriquencyMap[inputString];
	}

	return wordsFriquencyMap;
}

void PrintWordFriquency(map<string, int> wordsMap)
{
	for (auto const& wordPair : wordsMap)
	{
		cout << wordPair.first << "->" << wordPair.second << endl;
	}
}


int main(int argc, char * argv[])
{
	map<string, int> wordsMap = ReadStringsFromStream(cin);

	PrintWordFriquency(wordsMap);
	return 0;
}