#include <iostream>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>
#include <string>


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
	return (M_PI * degree) / 180;
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

using namespace std;

bool StringToDouble(string const& str, double & value)
{
	try
	{
		value = stod(str);
	}
	catch (std::exception const& )
	{
		return false;
	}
	return true;
}


int main(int argc, char* argv[])
{
	string inputString;
	cin >> inputString;
	
	if (inputString == "exit")
	{
		// exit
		return 1;
	}
	else
	{
		double angle;
		if (StringToDouble(inputString, angle))
		{
			// use angle
			cout << angle << endl;
		}
		else
		{
			// some error
			cout << "error" << endl;
		}
	}

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