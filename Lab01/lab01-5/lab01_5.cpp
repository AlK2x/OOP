#include <iostream>
#include <math.h>

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

	double speed, angle, distance, angleInRadian;
	double isExit = false;

	while (!exit)
	{
		std::cout << "Enter v0 (or type 'exit') ";
		std::cin >> speed;
		std::cout << "Enter a0 (or type 'exit') ";
		std::cin >> angle;
		angleInRadian = DegreeToRadian(angle);
		distance = CalculateDistance(speed, angleInRadian);
		std::cout << "Distance is " << distance << "\n";
		isExit = true;
	}

	std::cout << "Goodbye\n";

	return 0;
}