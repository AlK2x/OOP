#include <iostream>
#include <string.h>

// devide by zero
// overflow operation
// think about best structure

const char NO_STATEMENT = '\0';

double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

char ReadStatement(char* str, bool & err)
{
	char ch = NO_STATEMENT;
	if (strlen(str) == 1)
	{
		ch = str[0];
	}

	return ch;
}

double ComputeResult(double & leftArg, char statement, double rightArg)
{
	int result = 1;

	if (statement == '+')
	{
		leftArg = leftArg + rightArg;
	}
	else if (statement == '-')
	{
		leftArg = leftArg - rightArg;
	}
	else if (statement == '*')
	{
		leftArg = leftArg * rightArg;
	}
	else if (statement == '/')
	{
		leftArg = leftArg / rightArg;
	}
	else
	{
		result = 0;
	}

	return result;
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
				printf("Argument #%d is not a number\n.", i);
				return 1;
			}
			ComputeResult(result, statement, argument);
		}
		else
		{
			statement = ReadStatement(argv[i], err);
			if (err)
			{
				printf("Argument #%s is not a statement\n.", argv[i]);
				return 1;
			}
		}
		
	}

	printf("%.3f\n", result);

	return 0;
}
