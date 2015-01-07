#include "stdafx.h"
#include "Car.h"

using namespace std;

CCar::CCar() :m_engineOn(false), m_gear(0), m_speed(0)
{
	m_transmissionRanges[-1] = std::make_pair(-20, 0);
	m_transmissionRanges[0] = std::make_pair(0, 0);
	m_transmissionRanges[1] = std::make_pair(0, 30);
	m_transmissionRanges[2] = std::make_pair(20, 50);
	m_transmissionRanges[3] = std::make_pair(30, 60);
	m_transmissionRanges[4] = std::make_pair(40, 90);
	m_transmissionRanges[5] = std::make_pair(50, 150);
}

bool CCar::IsTurnedOn() const
{
	return m_engineOn;
}

bool CCar::TurnOnEngine()
{
	m_engineOn = true;
	return true;
}

bool CCar::TurnOffEngine()
{
	if (m_gear == 0 && m_speed == 0)
	{
		m_engineOn = false;
		return true;
	}
	
	return false;
}

int CCar::GetGear() const
{
	return m_gear;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

bool CCar::SetGear(int gear)
{
	if (gear == 0)
	{
		m_gear = gear;
		return true;
	}
	
	if (m_speed < 0 && gear > 0)
	{
		return false;
	}

	SpeedInterval speedIntervalForDesiredGear = m_transmissionRanges[gear];
	if (speedIntervalForDesiredGear.first <= abs(m_speed) && abs(speedIntervalForDesiredGear.second) >= abs(m_speed))
	{
		m_gear = gear;
		return true;
	}

	return false;;
}

bool CCar::SetSpeed(int speed)
{
	if (m_gear == 0 && std::abs(m_speed) >= std::abs(speed))
	{
		m_speed = speed;
		return true;
	}
	else if (m_gear == 0)
	{
		return false;
	}

	SpeedInterval possibleSpeedInterval = m_transmissionRanges[m_gear];

	if (possibleSpeedInterval.first <= speed && possibleSpeedInterval.second >= speed)
	{
		m_speed = speed;
		return true;
	}

	return false;
}

Direction CCar::GetDirection() const
{
	if (m_speed == 0)
	{
		return Direction::IN_PLACE;
	}
	else if (m_speed > 0)
	{
		return Direction::STRAIGHT;
	}
	else
	{
		return Direction::BACKWARD;
	}
}