#include <iostream>
#include <math.h>
#include <string.h>

const double PI = 3.14159265359;
const double G = 9.8;

double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

double DegreeToRadian(double degree)
{
	return (PI * degree) / 180;
}

double CalculateFlowTime(double speed, double angle)
{
	return 2 * speed * sin(angle) / G;
}

double CalculateDistance(double speed, double angle)
{
	return speed * CalculateFlowTime(speed, angle) * cos(angle);
}

int main(int argc, char* argv[])
{
	printf("Program calculates throwing distance.\n");

	const char exit[] = "exit";
	double speed, angle, distance, angleInRadian;
	double isExit = false;
	char buffer[80];

	while (!isExit)
	{
		printf("Enter v0 (or type 'exit') ");
		scanf("%s", buffer);
		if (strcmp(buffer, exit) != 0)
		{
			bool err;
			speed = StringToDouble(buffer, err);
			if (err)
			{
				printf("Error: %s is not allowed here. Number expected\n", buffer);
				continue;
			}
		}
		else
		{
			break;
		}
		printf("Enter a0 (or type 'exit') ");
		scanf("%s", buffer);
		if (strcmp(buffer, exit) != 0)
		{
			bool err;
			angle = StringToDouble(buffer, err);
			if (err)
			{
				printf("Error: %s is not allowed here. Number expected\n", buffer);
				continue;
			}
		}
		else
		{
			break;
		}
		angleInRadian = DegreeToRadian(angle);
		distance = CalculateDistance(speed, angleInRadian);
		std::cout << "Distance is " << distance << "\n";
	}

	std::cout << "Goodbye\n";

	return 0;
}