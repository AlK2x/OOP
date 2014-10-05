#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	const int LOWER_BOUND = 3;
	const int UPPER_BOUND = 107;
	const int STEP = 3;

	for (int i = UPPER_BOUND / STEP * STEP; i >= LOWER_BOUND; i -= STEP)
	{
		printf("%d", i);
		if (i - LOWER_BOUND >= STEP)
		{
			printf(", ");
		}
	}

	printf("\n");
	return 0;
}

