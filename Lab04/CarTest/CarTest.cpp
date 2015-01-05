#include "stdafx.h"
#include "../Car/Car.h"
using namespace std;

/*
	���������� ��������� ����������
		��������� ��������
		����� ��������� ��������� 
			����������� ��������
		 	�������� 0
		  	����� �� �����

	����� ����� ��������� ��������� �����:
	    ��������� ���������
		������������ �� 1-�� �������� � ���������� �� 30 - ����������� �����
		������������ �� ������ �������� � ���������� �� -20 - �����������  �����
			
	�� ������ ��������:
		������������ �� ������ ��� �������� 20-30
		������������ �� 3-� ��� 30
		������������ �� �������� � �����������
		�������� ������ ���, ���� �������� 0

	�� ������ ��������:
	    �������� �� ��������� �� 0 �� -20
		������������ ������ �� �������� � ������ �� �������� 0

	�� ������ ��������:
		�������� �� �������� 20-50
	    ������������ �� 1-� ��� �������� 20-30
		������������ �� 3-� ��� �������� 30-50
		������������ �� 4-� ��� 40-50
		������������ �� �������� � �����������

	�� ������� ��������:
		�������� �� �������� 30-60
		������������ �� 1-� ��� �������� 30
		������������ �� 2-� ��� �������� 30-50
		������������ �� 4-� ��� �������� 40-50
		������������ �� 5-� ��� 50
		������������ �� �������� � �����������

	�� ��������� ��������:
		�������� �� �������� 40-90
		������������ �� 2-� ��� �������� 40-50
		������������ �� 3-� ��� �������� 30-60
		������������ �� 5-� ��� �������� 50-90
		������������ �� �������� � �����������

	�� ��������� ��������:
		�������� �� �������� 50-150
		������������ �� 2-� ��� �������� 50
		������������ �� 3-� ��� �������� 50-60
		������������ �� 4-� ��� �������� 50-90
		������������ �� �������� � �����������
*/

struct JustCreatedCarFixture
{
	CCar car;
};

BOOST_FIXTURE_TEST_SUITE(JustCreatedCar, JustCreatedCarFixture)

BOOST_AUTO_TEST_CASE(IsEngineOff)
{
	BOOST_CHECK(!car.IsTurnedOn());
}

BOOST_AUTO_TEST_CASE(IsEngineOn)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.IsTurnedOn());
}

BOOST_AUTO_TEST_CASE(TestCarPropertiesJustAfterEngineTurnOn)
{
	BOOST_CHECK(car.GetGear() == 0);
	BOOST_CHECK(car.GetSpeed() == 0);
	BOOST_CHECK(car.GetDirection() == Direction::IN_PLACE);
}

BOOST_AUTO_TEST_SUITE_END()

struct JustAfterEngineOnCarFixture
{
	CCar car;
	JustAfterEngineOnCarFixture()
	{
		car.TurnOnEngine();
	}
};

BOOST_FIXTURE_TEST_SUITE(JustAfterEngineOnCar, JustAfterEngineOnCarFixture)

BOOST_AUTO_TEST_CASE(IsEngineOff)
{
	BOOST_CHECK(car.TurnOffEngine());
	BOOST_CHECK(!car.IsTurnedOn());
}

BOOST_AUTO_TEST_CASE(SetGearToBack)
{
	BOOST_CHECK(car.SetGear(-1));
}

BOOST_AUTO_TEST_CASE(SetGearTo1)
{
	BOOST_CHECK(car.SetGear(1));
}

BOOST_AUTO_TEST_CASE(SetGearTo2)
{
	BOOST_CHECK(!car.SetGear(2));
}

BOOST_AUTO_TEST_CASE(SetGearTo3)
{
	BOOST_CHECK(!car.SetGear(3));
}

BOOST_AUTO_TEST_CASE(SetGearTo4)
{
	BOOST_CHECK(!car.SetGear(4));
}

BOOST_AUTO_TEST_CASE(SetGearTo5)
{
	BOOST_CHECK(!car.SetGear(5));
}

BOOST_AUTO_TEST_CASE(SetFirstGearSpeedTest)
{
	car.SetGear(1);
	BOOST_CHECK(!car.SetSpeed(-1));
	BOOST_CHECK(car.GetSpeed() == 0);
	int i = 0;
	for (; i < 31; ++i)
	{
		BOOST_CHECK(car.SetSpeed(i));
		BOOST_CHECK(car.GetSpeed() == i);
	}

	BOOST_CHECK(car.GetDirection() == Direction::STRAIGHT);
	BOOST_CHECK(!car.SetSpeed(i));
	BOOST_CHECK(car.GetSpeed() == i - 1);
}

BOOST_AUTO_TEST_CASE(SetBackGearSpeedTest)
{
	car.SetGear(-1);
	BOOST_CHECK(!car.SetSpeed(1));
	BOOST_CHECK(car.GetSpeed() == 0);
	int i = 0;
	for (; i > -21; --i)
	{
		BOOST_CHECK(car.SetSpeed(i));
		BOOST_CHECK(car.GetSpeed() == i);
	}

	BOOST_CHECK(car.GetDirection() == Direction::BACKWARD);
	BOOST_CHECK(!car.SetSpeed(i));
	BOOST_CHECK(car.GetSpeed() == i + 1);
}

BOOST_AUTO_TEST_SUITE_END()

struct FirstGearTestFixture
{
	CCar car;
	FirstGearTestFixture()
	{
		car.TurnOnEngine();
		car.SetGear(1);
	}
};

BOOST_FIXTURE_TEST_SUITE(FirstGearTest, FirstGearTestFixture)

BOOST_AUTO_TEST_CASE(TestSpeedUpAndSwithcToSecondGear)
{
	car.SetSpeed(19);
	BOOST_CHECK(!car.SetGear(2));
	BOOST_CHECK(car.GetGear() == 1);

	car.SetSpeed(20);
	BOOST_CHECK(car.SetGear(2));
	BOOST_CHECK(car.GetGear() == 2);
}

BOOST_AUTO_TEST_CASE(TestSpeedUpAndSwithcToThirdGear)
{
	car.SetSpeed(29);
	BOOST_CHECK(!car.SetGear(3));
	BOOST_CHECK(car.GetGear() == 1);

	car.SetSpeed(30);
	BOOST_CHECK(car.SetGear(3));
	BOOST_CHECK(car.GetGear() == 3);
}

BOOST_AUTO_TEST_CASE(TestStopCar)
{
	car.SetSpeed(30);
	BOOST_CHECK(!car.TurnOffEngine());
	BOOST_CHECK(car.IsTurnedOn());

	car.SetSpeed(0);
	BOOST_CHECK(!car.TurnOffEngine());
	BOOST_CHECK(car.IsTurnedOn());

	car.SetGear(0);
	BOOST_CHECK(car.TurnOffEngine());
	BOOST_CHECK(!car.IsTurnedOn());
	BOOST_CHECK(car.GetGear() == 0);
	BOOST_CHECK(car.GetSpeed() == 0);
	BOOST_CHECK(car.GetDirection() == Direction::IN_PLACE);
}

BOOST_AUTO_TEST_CASE(TestSetForbiddenSpeedAndGear)
{
	BOOST_CHECK(!car.SetSpeed(31));
	BOOST_CHECK(!car.SetSpeed(-1));
	BOOST_CHECK(!car.SetGear(2));
	BOOST_CHECK(!car.SetGear(3));
	BOOST_CHECK(!car.SetGear(4));
	BOOST_CHECK(!car.SetGear(5));

	car.SetSpeed(10);
	BOOST_CHECK(!car.SetGear(-1));
}

BOOST_AUTO_TEST_CASE(TestBackGear)
{
	car.SetSpeed(10);
	BOOST_CHECK(!car.SetGear(-1));
	BOOST_CHECK(car.GetGear() == 1);

	car.SetSpeed(0);
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK(car.GetGear() == -1);
}

BOOST_AUTO_TEST_SUITE_END()

struct BackGearTestFixture
{
	CCar car;
	BackGearTestFixture()
	{
		car.TurnOnEngine();
		car.SetGear(-1);
	}
};

BOOST_FIXTURE_TEST_SUITE(BackGearTest, BackGearTestFixture)

BOOST_AUTO_TEST_CASE(TestBackSpeed)
{
	BOOST_CHECK(car.SetSpeed(-1));
	BOOST_CHECK(car.SetSpeed(-20));
	BOOST_CHECK(!car.SetSpeed(-21));
}

BOOST_AUTO_TEST_CASE(TestSwithcGear)
{
	car.SetSpeed(-20);
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK(!car.SetGear(1));
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.SetGear(1));
}

BOOST_AUTO_TEST_SUITE_END()

struct SecondGearTestFixture
{
	CCar car;
	SecondGearTestFixture()
	{
		car.TurnOnEngine();
		car.SetGear(1);
		car.SetSpeed(20);
		car.SetGear(2);
	}
};

BOOST_FIXTURE_TEST_SUITE(SecondGearTest, SecondGearTestFixture)

BOOST_AUTO_TEST_CASE(TestSecondGearSpeedLimit)
{
	BOOST_CHECK(!car.SetSpeed(19));
	BOOST_CHECK(!car.SetSpeed(51));
	BOOST_CHECK(car.GetSpeed() == 20);
	BOOST_CHECK(car.SetSpeed(21));
	BOOST_CHECK(car.GetSpeed() == 21);
	BOOST_CHECK(car.SetSpeed(50));
	BOOST_CHECK(car.GetSpeed() == 50);
}

BOOST_AUTO_TEST_CASE(TestSpeedUpAndSwithcToThirdGear)
{
	car.SetSpeed(29);
	BOOST_CHECK(!car.SetGear(3));
	BOOST_CHECK(car.GetGear() == 2);

	car.SetSpeed(30);
	BOOST_CHECK(car.SetGear(3));
	BOOST_CHECK(car.GetGear() == 3);
}

BOOST_AUTO_TEST_CASE(TestSpeedUpAndSwithcToFourthGear)
{
	car.SetSpeed(39);
	BOOST_CHECK(!car.SetGear(4));
	BOOST_CHECK(car.GetGear() == 2);

	car.SetSpeed(40);
	BOOST_CHECK(car.SetGear(4));
	BOOST_CHECK(car.GetGear() == 4);
}

BOOST_AUTO_TEST_SUITE_END()