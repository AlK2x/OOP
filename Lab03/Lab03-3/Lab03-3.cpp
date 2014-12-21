#include "stdafx.h"
#include "StringsMap.h"

using namespace std;

int main(int argc, char * argv[])
{
	map<string, int> wordsMap = ReadStringsFromStream(cin);

	PrintWordFriquency(wordsMap);
	return 0;
}