// lab6_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Rational.h"


BOOST_AUTO_TEST_SUITE(Rational)

// –ациональное число по умолчанию равно 0/1
BOOST_AUTO_TEST_CASE(RationalIs0_1ByDefault)
{
	CRational const r;
	BOOST_CHECK_EQUAL(r.GetNumerator(), 0);
	BOOST_CHECK_EQUAL(r.GetDenominator(), 1);
}

// ÷елое число N €вл€етс€ рациональным вида N/1
BOOST_AUTO_TEST_CASE(IntegerIsRational_N_1)
{
	{
		CRational const r(42);
		BOOST_CHECK_EQUAL(r.GetNumerator(), 42);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 1);
	}

	{
		CRational const r(0);
		BOOST_CHECK_EQUAL(r.GetNumerator(), 0);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 1);
	}

	{
		CRational const r(-42);
		BOOST_CHECK_EQUAL(r.GetNumerator(), -42);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 1);
	}
}

// ƒробное число N / M €вл€етс€ рациональным вида N/M
BOOST_AUTO_TEST_CASE(FractionIsRational_N_M)
{
	{
		CRational const r(-42, 5);
		BOOST_CHECK_EQUAL(r.GetNumerator(), -42);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 5);
	}
}

// –ациональные числа равны если равны их числители и знаменатели
BOOST_AUTO_TEST_CASE(RationalsEquality)
{
	BOOST_CHECK(CRational(2, 3) == CRational(2, 3));
	BOOST_CHECK(!(CRational(2, 3) == CRational(5, 8)));
	BOOST_CHECK(!(CRational(2, 5) == CRational(2, 3)));
	BOOST_CHECK(!(CRational(2, 3) == CRational(1, 3)));
}

// –ациональные числа не равны если не равны их числители
// либо не равны их знаменатели
BOOST_AUTO_TEST_CASE(RationalsInequality)
{
	BOOST_CHECK(!(CRational(2, 3) != CRational(2, 3)));
	BOOST_CHECK(CRational(2, 3) != CRational(5, 8));
	BOOST_CHECK(CRational(2, 5) != CRational(2, 3));
	BOOST_CHECK(CRational(2, 3) != CRational(1, 3));
}

// —ложение дробей с несократимыми знаменател€ми
BOOST_AUTO_TEST_CASE(Sum1)
{
	BOOST_CHECK(CRational(1, 2) + CRational(1, 3) == CRational(5, 6));
	CRational r(1, 2);
	// ќператор += возвращает ссылку на левый операнд
	BOOST_CHECK_EQUAL(&(r += CRational(1, 3)), &r);
	// –езультат должен быть сохранен в левом операнде
	BOOST_CHECK(r == CRational(5, 6));
}

BOOST_AUTO_TEST_CASE(SelfAddition)
{
	CRational r(2);
	r += r;
	BOOST_CHECK(r == CRational(4));
}

BOOST_AUTO_TEST_CASE(ComputeGcd)
{
	BOOST_CHECK_EQUAL(GCD(6, 8), 2);
	BOOST_CHECK_EQUAL(GCD(0, 8), 8);
	BOOST_CHECK_EQUAL(GCD(0, 0), 0);
	BOOST_CHECK_EQUAL(GCD(3, 5), 1);
	BOOST_CHECK_EQUAL(GCD(1, 1), 1);
	BOOST_CHECK_EQUAL(GCD(3, 3), 3);
	BOOST_CHECK_EQUAL(GCD(1, 5), 1);
	BOOST_CHECK_EQUAL(GCD(3, 1), 1);
}

//рациональные числа хран€тс€ в виде несократимых дробей натуральным знаменателем
BOOST_AUTO_TEST_CASE(RationalsAreNormalizedAfterCreation)
{
	{
		CRational r(6, 8);
		BOOST_CHECK_EQUAL(r.GetNumerator(), 3);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 4);
	}

	{
		CRational r(6, -8);
		BOOST_CHECK_EQUAL(r.GetNumerator(), -3);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 4);
	}

	{
		CRational r(-6, 8);
		BOOST_CHECK_EQUAL(r.GetNumerator(), -3);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 4);
	}

	{
		CRational r(-6, -8);
		BOOST_CHECK_EQUAL(r.GetNumerator(), 3);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 4);
	}

	{
		CRational r(-10, 20);
		BOOST_CHECK_EQUAL(r.GetNumerator(), -1);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 2);
	}
}

BOOST_AUTO_TEST_CASE(DenominatorMustNotBeZero)
{
	BOOST_CHECK_THROW((CRational(0, 0)), std::invalid_argument);
	BOOST_CHECK_THROW((CRational(1, 0)), std::invalid_argument);
}

// ѕосле сложени€ результат нормализован
BOOST_AUTO_TEST_CASE(AdditionResultIsNormalized)
{
	BOOST_CHECK((CRational(1, 2) += CRational(1, 6)) == CRational(2, 3));
	BOOST_CHECK((CRational(1, 2) + CRational(1, 6)) == CRational(2, 3));
}

BOOST_AUTO_TEST_CASE(Multiplication)
{
	CRational r(2, 5);
	// ќператор *= возвращает ссылку на левый операнд
	BOOST_CHECK_EQUAL(&(r *= CRational(5, 4)), &r);
	// –езультат должен быть сохранен в левом операнде
	BOOST_CHECK(r == CRational(1, 2));
	BOOST_CHECK((CRational(-2, 5) * CRational(5, 4)) == CRational(-1, 2));
}

BOOST_AUTO_TEST_CASE(AdditionWithInteger)
{
	BOOST_CHECK(CRational(1, 2) + 1 == CRational(3, 2));
	BOOST_CHECK(1 + CRational(1, 2) == CRational(3, 2));
}

BOOST_AUTO_TEST_CASE(MultiplicationWithInteger)
{
	BOOST_CHECK(CRational(1, 2) * 3 == CRational(3, 2));
	BOOST_CHECK(3 * CRational(1, 2) == CRational(3, 2));
}

BOOST_AUTO_TEST_SUITE_END()
