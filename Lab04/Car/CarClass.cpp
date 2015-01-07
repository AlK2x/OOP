#include "stdafx.h"
#include "Car.h"
#include <iostream>
#include <string>

using namespace std;

string GetDirectionAsString(Direction direction)
{
	string directionString;
	switch (direction)
	{
	case Direction::STRAIGHT:
		directionString = "Straight";
		break;
	case Direction::IN_PLACE:
		directionString = "In place";
		break;
	case Direction::BACKWARD:
		directionString = "Back";
		break;
	default:
		directionString = "Through the wormhole";
	}

	return directionString;
}

void ShowInfo(const CCar & car)
{
	string engineState = car.IsTurnedOn() ? "On" : "Off";
	cout << "==== Car Info ====" << endl;
	cout << "Engine   : " << engineState << endl;
	cout << "Direction: " << GetDirectionAsString(car.GetDirection()) << endl;
	cout << "Speed    : " << car.GetSpeed() << endl;
	cout << "Gear     : " << car.GetGear() << endl;
	cout << endl;
}

void SetNewGear(CCar & car, int gear)
{
	if (!car.SetGear(gear))
	{
		if (!car.IsTurnedOn())
		{
			cout << "Car can't move with engine off!\n";
		}
		else
		{
			int speed = car.GetSpeed();
			cout << "Can't switch to " << gear << " gear on " << speed << " speed\n";
		}
	}
}

void SetNewSpeed(CCar & car, int speed)
{
	if (!car.SetSpeed(speed))
	{
		if (!car.IsTurnedOn())
		{
			cout << "Car can't move with engine off!\n";
		}
		else
		{
			int gear = car.GetGear();
			cout << "Can't change speed to " << speed << " on " << gear << "-th gear\n";
		}
	}
}

void PlayTheGame()
{
	CCar car;
	string command;
	cout << "Greetings and welcome... I want to play a game.\n";
	while (true)
	{
		cin >> command;
		if (command == "Exit")
		{
			break;
		}
		else if (command == "Info")
		{
			ShowInfo(car);
		}
		else if (command == "EngineOn")
		{
			car.TurnOnEngine();
		}
		else if (command == "EngineOff")
		{
			car.TurnOffEngine();
		}
		else if (command == "SetGear")
		{
			int gear;
			cin >> gear;
			SetNewGear(car, gear);
		}
		else if (command == "SetSpeed")
		{
			int speed;
			cin >> speed;
			SetNewSpeed(car, speed);
		}
		cin.clear();
	}
}

void PrintGameRule()
{
	cout << "Commands:" << endl;
	cout << "        Exit - for quit" << endl;
	cout << "        Info - print auto info" << endl;
	cout << "        EngineOn" << endl;
	cout << "        EngineOff" << endl;
	cout << "        SetGear <gear>" << endl;
	cout << "        SetSpeed <speed>" << endl;
	cout << endl;
}

int main(int argc, char * argv[])
{
	PrintGameRule();
	PlayTheGame();
	return 0;
}

