#include "stdafx.h"
#include "Rational.h"

unsigned GCD(unsigned x, unsigned y)
{
	while (x != 0)
	{
		std::swap(x, y);
		x %= y;
	}
	return y;
}

CRational::CRational(int numerator, int denominator)
{
	Assign(numerator, denominator);
}

// Возвращаем числитель
int CRational::GetNumerator()const
{
	return m_numerator;
}

// Возвращаем знаменатель
int CRational::GetDenominator()const
{
	return m_denominator;
}

bool CRational::operator==(CRational const & rhs)const
{
	return (rhs.m_numerator == m_numerator && 
			rhs.m_denominator == m_denominator);
}

bool CRational::operator!=(CRational const & rhs)const
{
	return !(*this == rhs);
}

CRational& CRational::operator+=(CRational const& rhs)
{
	Assign(rhs.m_numerator * m_denominator + 
		   rhs.m_denominator * m_numerator, 
		   m_denominator * rhs.m_denominator);

	return *this;
}

CRational& CRational::operator-=(CRational const& rhs)
{
	Assign(m_numerator * rhs.m_denominator -
		rhs.m_numerator * m_denominator,
		m_denominator * rhs.m_denominator);
	return *this;
}

CRational const CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}

CRational const CRational::operator+() const
{
	return CRational(m_numerator, m_denominator);
}

void CRational::Assign(int numerator, int denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator must not be zero");
	}
	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}
	int gcd = GCD(std::abs(numerator), denominator);
	m_numerator = numerator / gcd;
	m_denominator = denominator / gcd;
}

CRational& CRational::operator*=(CRational const & rhs)
{
	Assign(rhs.m_numerator * m_numerator, rhs.m_denominator * m_denominator);
	return *this;
}

CRational& CRational::operator/=(CRational const & rhs)
{
	Assign(m_numerator * rhs.m_denominator, m_denominator * rhs.m_numerator);
	return *this;
}

CRational const operator+(CRational lhs,
	                      CRational const & rhs)
{
	return lhs += rhs;
}

CRational const operator*(CRational lhs,
	CRational const & rhs)
{
	return lhs *= rhs;
}

CRational const operator-(CRational lhs, CRational const & rhs)
{
	return lhs -= rhs;
}

CRational const operator/(CRational lhs, CRational const & rhs)
{
	return lhs /= rhs;
}

std::ostream& operator<<(std::ostream & ost, CRational const & rhs)
{
	ost << rhs.GetNumerator() << '/' << rhs.GetDenominator();
	return ost;
}

std::istream& operator>>(std::istream & ist, CRational & rhs)
{
	std::streamoff pos = ist.tellg();

	int numerator, denominator;
	if (ist >> numerator)
	{
		if (ist.get() == '/' && (ist >> denominator))
		{
			rhs = CRational(numerator, denominator);
		}
		else
		{
			rhs = CRational(numerator);
		}
		return ist;
	}

	ist.seekg(pos);
	ist.setstate(std::ios_base::failbit | ist.rdstate());
	return ist;
}