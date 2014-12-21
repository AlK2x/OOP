#include "stdafx.h"
#include "TvSet.h"


CTvSet::CTvSet()
:m_turnedOn(false), m_channel(1)
{
}

bool CTvSet::IsTurnedOn()const
{
	return m_turnedOn;
}

unsigned CTvSet::GetChannel()const
{
	return IsTurnedOn() ? m_channel : 0;
}

bool CTvSet::TurnOn()
{
	m_channel = m_channel;
	m_turnedOn = true;
	return m_turnedOn;
}

bool CTvSet::TurnOff()
{
	m_turnedOn = false;
	return true;
}

bool CTvSet::SelectChannel(unsigned channel)
{
	m_channel = channel;
	return true;
}

unsigned CTvSet::ReturnChannel()
{
	return true;
}

CTvSet::~CTvSet()
{
}
