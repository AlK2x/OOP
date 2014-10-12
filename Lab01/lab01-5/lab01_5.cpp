#include <iostream>
#include <math.h>
#include <string.h>

const double PI = 3.14159265359;
const double G = 9.8;

enum InputAction
{
	CONTINUE,
	EXIT
};

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

double ReadUserInput(char * buffer, const char * stringForExit, InputAction & action)
{
	double input = 0.0;
	action = CONTINUE;
	scanf("%s", buffer);
	if (strcmp(buffer, stringForExit) != 0)
	{
		bool err;
		input = StringToDouble(buffer, err);
		if (err)
		{
			printf("Error: %s is not allowed here. Positive number expected.\n", buffer);
		}
	}
	else
	{
		action = EXIT;
	}

	return input;
}

int main(int argc, char* argv[])
{
	printf("Program calculates throwing distance.\n");

	const char stringForExit[] = "exit";
	double speed, angle, distance, angleInRadian;
	char buffer[80];
	InputAction userAction;

	for (;;)
	{
		printf("Enter v0 (or type 'exit') ");
		speed = ReadUserInput(buffer, stringForExit, userAction);
		if (userAction != CONTINUE)
		{
			break;
		}

		printf("Enter a0 (or type 'exit') ");
		angle = ReadUserInput(buffer, stringForExit, userAction);
		if (userAction != CONTINUE)
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