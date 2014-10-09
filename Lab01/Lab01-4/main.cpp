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

int SafeAddition(int firstTerm, int secondTerm, bool & overflow)
{
	overflow = (firstTerm > 0 && INT_MAX - secondTerm < firstTerm) || (firstTerm < 0 && INT_MIN - secondTerm > firstTerm);

	return firstTerm + secondTerm;
}

int main(int argc, char* argv[])
{
	const int FIBONACHI_FIRST = 1;
	const int FIBONACHI_SECOND = 1;
	const int NUMBERS_IN_LINE = 6;

	if (argc <= 1)
	{
		printf("Program calculates fibonacchi sequence.\n");
		return 1;
	}

	bool err;

	long inputNum = StringToInt(argv[1], err);
	if (err)
	{
		printf("Parameter %d is not an integer\n", inputNum);
		return 1;
	}

	long fibResult = FIBONACHI_FIRST + FIBONACHI_SECOND;
	long firstFibNum = FIBONACHI_FIRST;
	long secondFibNum = FIBONACHI_SECOND;
	int fibCounter = 0;
	bool overflow;

	while (inputNum >= fibResult)
	{
		printf("%6u, ", secondFibNum);
		fibResult = SafeAddition(firstFibNum, secondFibNum, overflow);
		if (overflow)
		{
			break;
		}

		secondFibNum = firstFibNum;
		firstFibNum = fibResult;
		++fibCounter;
		if ((fibCounter % NUMBERS_IN_LINE) == 0)
		{
			printf("\n");
		}
	}

	printf("%6u \n", secondFibNum);

	return 0;
}