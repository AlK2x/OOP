#include <iostream>
#include <string.h>

enum Error
{
	NO_ERROR,
	INCORRECT_PARAMETER,
	DIVIDE_BY_ZERO,
	NOT_NUMBER
};

double StringToDouble(const char * str, Error & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0')) ? INCORRECT_PARAMETER : NO_ERROR;
	return param;
}

char ReadStatement(char* str, Error & err)
{
	err = INCORRECT_PARAMETER;
	char statement = '\0';
	if (strlen(str) > 0)
	{
		statement = str[0];
		switch (statement)
		{
		case '+': case '-': case '*': case '/':
			err = NO_ERROR;
			break;
		default:
			break;
		}
	}

	return statement;
}

Error ComputeResult(double & leftArg, char statement, double rightArg)
{
	Error result = NO_ERROR;
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
			result = DIVIDE_BY_ZERO;
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

void PrintErrorMessage(Error errorCode)
{
	if (errorCode == DIVIDE_BY_ZERO)
	{
		printf("Devide by zero position.");
	}
	else if (errorCode == INCORRECT_PARAMETER)
	{
		printf("Unknown parameter. Only +, -, *, / allowed");
	}
}

double CalculateExpression(double firstParameter, int argc, char* argv[], Error & error)
{
	error = NO_ERROR;
	double argument = firstParameter;
	char statement = '\0';
	for (int i = 2; i < argc && (error == NO_ERROR); ++i)
	{
		if ((i % 2) != 0)
		{
			argument = StringToDouble(argv[i], error);
			if (error == NO_ERROR) 
			{
				error = ComputeResult(firstParameter, statement, argument);
			}
		}
		else
		{
			statement = ReadStatement(argv[i], error);
		}
	}
	return firstParameter;
}

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		printf("Program calculates ariphmetical operation of its command line arguments with no priority of operations.\n");
		return 0;
	}

	int sum = 0;
	Error err;

	double result = StringToDouble(argv[1], err);
	if (err)
	{
		printf("Argument #%d is not a number\n.", 1);
		return 1;
	}

	result = CalculateExpression(result, argc, argv, err);

	if (err == NO_ERROR)
	{
		printf("%.3f\n", result);
	}
	else
	{
		PrintErrorMessage(err);
		return 1;
	}

	return 0;
}
