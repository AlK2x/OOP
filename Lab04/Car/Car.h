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
	bool SetSpeed(unsigned);

private:
	typedef int Gear;
	typedef std::pair<unsigned, unsigned> SpeedInterval;
	typedef std::unordered_map<Gear, SpeedInterval> TransmissionRanges;

	void UpdateDirection();
	static CCar::TransmissionRanges m_transmissionRanges;

	bool m_engineOn;
	unsigned m_speed;
	Direction m_direction;
	Gear m_gear;
};

