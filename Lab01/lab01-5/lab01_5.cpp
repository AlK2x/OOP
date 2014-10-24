#include <iostream>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>
#include <string>

using namespace std;

const double G = 9.8;

enum class InputAction
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

bool ReadUserInput(double & input)
{
	string buffer;
	cin >> buffer;
	double input = 0.0;
	
	if (buffer.compare("exit"))
	{
		if (!StringToDouble(buffer, input))
		{
			printf("Error: %s is not allowed here. Positive number expected.\n", buffer);
		}
	}
	else
	{
		action = InputAction::EXIT;
	}

	return input;
}



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

	double speed, angle, distance, angleInRadian;
	const string stringForExit = "exit";
	

	for (;;)
	{
		printf("Enter v0 (or type 'exit') ");
		speed = ReadUserInput();
		if (userAction != InputAction::CONTINUE)
		{
			break;
		}

		printf("Enter a0 (or type 'exit') ");
		angle = ReadUserInput();
		if (userAction != InputAction::CONTINUE)
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