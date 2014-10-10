#include <iostream>
#include "common.h"

// last digit on big nubers(max bound)
// names of variables prev, next, current
// print fibonacci in functions

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

void PrintFibonacciNumbers(int noGreatherThen, int digitsInLine)
{
	long current = 1;
	long previous = 1;
	int next = current + previous;
	int fibCounter = 1;

	printf("%10u ", previous);

	while (noGreatherThen >= next)
	{
		bool overflow;
		next = SafeAddition(current, previous, overflow);
		printf("%10u ", current);
		if (overflow)
		{
			printf("\n");
			return;
		}

		previous = current;
		current = next;
		++fibCounter;
		if ((fibCounter % digitsInLine) == 0)
		{
			printf("\n");
		}
	}
	printf("\n");
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

	PrintFibonacciNumbers(inputNum, NUMBERS_IN_LINE);

	return 0;
}