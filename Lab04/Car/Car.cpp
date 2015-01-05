#include "stdafx.h"
#include "Car.h"

CCar::CCar() :m_engineOn(false), m_gear(0), m_speed(0)
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
	bool setGearResult = false;
	if (m_speed == 0)
	{
		if (gear == 0 || gear == -1 || gear == 1)
		{
			m_gear = gear;
			setGearResult = true;
		}
	}
	else if (m_speed >= 20 && m_speed <= 30)
	{
		if (gear == 0 || gear == 2 || (m_speed == 30 && gear == 3))
		{
			m_gear = gear;
			setGearResult = true;
		}
	}

	if (m_gear == -1)
	{
		if (gear == 0)
		{
			m_gear = gear;
			setGearResult = true;
		}
	}
	else if (m_gear == 2)
	{
		if (m_speed >= 20 && m_speed <= 30 && gear == 1)
		{
			m_gear = gear;
			setGearResult = true;
		}
		else if (m_speed >= 30 && m_speed <= 50 && gear == 3)
		{
			m_gear = gear;
			setGearResult = true;
		}
		else if (gear == 4 && m_speed >= 40 && m_speed <= 50)
		{
			m_gear = gear;
			setGearResult = true;
		}
	}

	return setGearResult;;
}

bool CCar::SetSpeed(int speed)
{
	bool setSpeedResult = false;
	if (m_gear == 1)
	{
		if (speed >= 0 && speed <= 30)
		{
			m_speed = speed;
			setSpeedResult = true;
		}
	}
	else if (m_gear == 0)
	{
		m_speed = speed;
		setSpeedResult = true;
	}
	else if (m_gear == -1)
	{
		if (speed <= 0 && speed >= -20)
		{
			m_speed = speed;
			setSpeedResult = true;
		}
	}
	else if (m_gear == 2)
	{
		if (speed >= 20 && speed <= 50)
		{
			m_speed = speed;
			setSpeedResult = true;
		}
	}

	return setSpeedResult;
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