#pragma once
#include "Direction.h"
#include <utility>
#include <unordered_map>
#include <cstdlib>

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
	typedef int Gear;
	typedef std::pair<int, int> SpeedInterval;
	typedef std::unordered_map<Gear, SpeedInterval> TransmissionRanges;

	bool m_engineOn;
	int m_speed;
	Gear m_gear;
	TransmissionRanges m_transmissionRanges;
};

