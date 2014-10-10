#include <iostream>
#include <string.h>
#include "common.h"

// style
// devide main
// enum for errors double

double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

char ReadStatement(char* str, bool & err)
{
	char ch = INCORRECT_PARAMETER;
	err = strlen(str) != 1;
	if (!err)
	{
		ch = str[0];
		switch (ch)
		{
		case '+': case '-': case '*': case '/':
			break;
		default:
			err = true;
			break;
		}
	}

	return ch;
}

char ComputeResult(double & leftArg, char statement, double rightArg)
{
	int result = OK;

	if (statement == '+')
	{
		leftArg += rightArg;
	}
	else if (statement == '-')
	{
		leftArg -= rightArg;
	}
	else if (statement == '*')
	{
		leftArg *= rightArg;
	}
	else if (statement == '/')
	{
		if (rightArg == 0)
		{
			result = DEVIDE_BY_ZERO;
		}
		else
		{
			leftArg /= rightArg;
		}
	}
	else
	{
		result = INCORRECT_PARAMETER;
	}

	return result;
}

void printErrorMessage(char errorCode, int errorPosition)
{
	if (errorCode == DEVIDE_BY_ZERO)
	{
		printf("Devide by zero in %d position.", errorPosition);
	}
	else if (errorCode == INCORRECT_PARAMETER)
	{
		printf("Unknown %d parameter. Only +, -, *, / allowed", errorPosition);
	}
}

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		printf("Program calculates ariphmetical operation of its command line arguments with no priority of operations.\n");
		return 0;
	}

	int sum = 0;

	char statement;
	double argument;
	bool err;

	double result = StringToDouble(argv[1], err);
	if (err)
	{
		printf("Argument #%d is not a number\n.", 1);
		return 1;
	}

	for (int i = 2; i < argc; ++i)
	{
		
		if ((i % 2) != 0)
		{
			argument = StringToDouble(argv[i], err);
			if (err)
			{
				printf("Argument #%d is not a number\n", i);
				return 1;
			}

			int computeErrorCode = ComputeResult(result, statement, argument);
			if (computeErrorCode != OK)
			{
				printErrorMessage(computeErrorCode, i);
				return 1;
			}
		}
		else
		{
			statement = ReadStatement(argv[i], err);
			if (err || statement == INCORRECT_PARAMETER)
			{
				printErrorMessage(statement, i);
				return 1;
			}
		}
		
	}

	printf("%.3f\n", result);

	return 0;
}
