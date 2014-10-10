#include <iostream>
#include <assert.h>

int SumDigits(int i)
{
	int sum = 0;

	while (i != 0)
	{
		sum += i % 10;
		i /= 10;
	}

	return sum;
}

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

void PrintNumbers(int lowBound, int upperBound)
{
	printf("1");
	++lowBound;
	for (int i = lowBound; i <= upperBound; ++i)
	{
		if ((i % SumDigits(i)) == 0)
		{
			printf(", %d", i);
		}
	}
}


int main(int argc, char* argv[])
{
	const int LOWER_BOUND = 1;
	int upperBound = 1000;
	bool hasError;

	if (argc >= 2)
	{
		int inputValue = StringToInt(argv[1], hasError);
		if (hasError || inputValue <= LOWER_BOUND)
		{
			printf("Invalid argument. It must be a digit greather then one.\n");
			return 1;
		}

		upperBound = inputValue;
	}

	PrintNumbers(LOWER_BOUND, upperBound);

	printf("\n");

	return 0;
}

