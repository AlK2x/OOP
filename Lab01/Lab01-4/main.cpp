#include <iostream>
#include "common.h"

// handle overflow
// handle incorrect parameter
// think about the best computation

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

int main(int argc, char* argv[])
{
	const int FIBONACHI_FIRST = 1;
	const int FIBONACHI_SECOND = 1;

	if (argc <= 1)
	{
		printf("Program calculates sum of its command line arguments.\n");
		return 0;
	}

	bool err;

	long inputNum = StringToInt(argv[1], err);
	if (err)
	{
		// hander error
	}

	long fibResult = FIBONACHI_FIRST + FIBONACHI_SECOND;
	long firstFibNum = FIBONACHI_FIRST;
	long secondFibNum = FIBONACHI_SECOND;

	while (inputNum >= fibResult)
	{
		fibResult = firstFibNum + secondFibNum;
		secondFibNum = firstFibNum;
		firstFibNum = fibResult;
	}

	printf("%u \n", secondFibNum);

	return 0;
}