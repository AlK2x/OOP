#include "stdafx.h"
#include "../Lab04-1/TvSet.h"

using namespace std;

/**
	���������� ��������� ���������
		�������� 
		����� ������ �������
		����� ��������� ����� ������� �� ������ ������

	���������� ��������� 
		����� ��������� ����� �������� � �������� �� ������� ������
		��������� ������� ����� ������
		��� ��������� ��������� ���������� false � ��������� ����� ������
*	
*/

struct JustCreatedTvSetFixture
{
	CTvSet tv;
};


BOOST_FIXTURE_TEST_SUITE(JustCreatedTvSet, JustCreatedTvSetFixture)

	BOOST_AUTO_TEST_CASE(IsTurnedOff)
	{
		BOOST_CHECK(!tv.IsTurnedOn());
	}

	BOOST_AUTO_TEST_CASE(TvOffChannel)
	{
		BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
	}

	BOOST_AUTO_TEST_CASE(BeeingTurnedOnIsTurnOnAtChannel1)
	{
		BOOST_CHECK(tv.TurnOn());
		BOOST_CHECK(tv.IsTurnedOn());
		BOOST_CHECK(tv.GetChannel() == 1);
	}

	BOOST_AUTO_TEST_CASE(SwitchChannelTest)
	{
		BOOST_CHECK(tv.TurnOn());
		tv.SelectChannel(10);
		BOOST_CHECK_EQUAL(tv.GetChannel(), 10);
	}

BOOST_AUTO_TEST_SUITE_END()

struct TurnedOnTvSetFixture
{
	CTvSet tv;
	TurnedOnTvSetFixture()
	{
		tv.TurnOn();
	}
	
};

BOOST_FIXTURE_TEST_SUITE(TurnedOnTvSet, TurnedOnTvSetFixture)

BOOST_AUTO_TEST_CASE(BeeingTurnedOffTvCanBeTurnedOff)
{
	BOOST_CHECK(tv.TurnOff());
	BOOST_CHECK(!tv.IsTurnedOn());
	BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
}

BOOST_AUTO_TEST_CASE(AllowingSwitchingChannel)
{
	BOOST_CHECK(tv.SelectChannel(42));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 42);
}

BOOST_AUTO_TEST_CASE(BeengTurnedOnAndOffRestoresChannel)
{
	BOOST_CHECK(tv.SelectChannel(42));
	BOOST_CHECK(tv.TurnOff());
	BOOST_CHECK(tv.TurnOn());
	BOOST_CHECK(tv.IsTurnedOn());
	BOOST_CHECK_EQUAL(tv.GetChannel(), 42);
}

BOOST_AUTO_TEST_SUITE_END()