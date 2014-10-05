#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int i;
	for (i = 100; i >= 1; i -= 2)
	{
		printf("%d", i);
		if (i != 2)
		{
			printf(", ");
		}
	}
	printf("\n");

	return 0;
}

