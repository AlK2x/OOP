#pragma once
class CTvSet
{
public:
	CTvSet();

	bool IsTurnedOn()const;
	unsigned GetChannel() const;
	bool TurnOn();
	bool TurnOff();
	bool SelectChannel(unsigned);
	unsigned ReturnChannel();

	~CTvSet();

private:
	bool m_turnedOn;
	unsigned short m_channel;
};

