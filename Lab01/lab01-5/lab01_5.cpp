#include <iostream>
#include <math.h>

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

int main(int argc, char* argv[])
{
	const double PI = 3.14159265359;

	printf("Program calculates throwing distance.\n");

	

	return 0;
}