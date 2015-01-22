#include "stdafx.h"
#include "Car.h"

using namespace std;

const CCar::TransmissionRanges CCar::m_transmissionRanges = {
	{ -1, { 0, 20 } },
	{ 0, { 0, 0 } },
	{ 1, { 0, 30 } },
	{ 2, { 20, 50 } },
	{ 3, { 30, 60 } },
	{ 4, { 40, 90 } },
	{ 5, { 50, 150 } }
};

CCar::CCar() :m_engineOn(false), m_gear(0), m_speed(0), m_direction(Direction::IN_PLACE)
{
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
	UpdateDirection();
	if (!m_engineOn)
	{
		return false;
	}

	if (gear == 0)
	{
		m_gear = gear;
		return true;
	}
	if ((gear < 0 && m_gear > 0 && m_speed > 0) || (m_speed > 0 && m_direction == Direction::BACKWARD))
	{
		return false;
	}

	SpeedInterval speedIntervalForDesiredGear = CCar::m_transmissionRanges[gear];
	if (speedIntervalForDesiredGear.first <= m_speed && speedIntervalForDesiredGear.second >= m_speed)
	{
		m_gear = gear;
		return true;
	}

	return false;
}

bool CCar::SetSpeed(unsigned speed)
{
	UpdateDirection();
	if (!m_engineOn)
	{
		return false;
	}

	if (m_gear == 0 && m_speed >= speed)
	{
		m_speed = speed;
		return true;
	}
	else if (m_gear == 0)
	{
		return false;
	}

	SpeedInterval possibleSpeedInterval = CCar::m_transmissionRanges[m_gear];

	if (possibleSpeedInterval.first <= speed && possibleSpeedInterval.second >= speed)
	{
		m_speed = speed;
		return true;
	}

	return false;
}

Direction CCar::GetDirection() const
{
	return m_direction;
}

void CCar::UpdateDirection()
{
	if (m_speed == 0)
	{
		m_direction = Direction::IN_PLACE;
	}
	else if (m_gear > 0)
	{
		m_direction = Direction::STRAIGHT;
	}
	else
	{
		m_direction = Direction::BACKWARD;
	}
}