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
		cout << "Oops. Something goes wrong!\n";
	}
}

void SetNewSpeed(CCar & car, int speed)
{
	if (!car.SetSpeed(speed))
	{
		cout << "Oops. Something goes wrong!\n";
	}
}

void PlayTheGame(CCar & car)
{
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
	}
}


int main(int argc, char * argv[])
{
	CCar car;
	PlayTheGame(car);
	return 0;
}

