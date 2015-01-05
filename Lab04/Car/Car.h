#pragma once
#include "Direction.h"

class CCar
{
public:
	CCar();

	bool IsTurnedOn() const;
	bool TurnOnEngine();
	bool TurnOffEngine();

	int GetGear() const;
	int GetSpeed() const;
	Direction GetDirection() const;

	bool SetGear(int);
	bool SetSpeed(int);

private:
	bool m_engineOn;
	int m_speed;
	int m_gear;
};

