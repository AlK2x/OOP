#pragma once
#include "IShape.h"
#include <string>
class CPoint : public IShape
{
public:
	CPoint();
	CPoint(double x, double y);

	double GetX() const;
	double GetY() const;

	virtual std::string ToString() const override;
	virtual double GetArea() const override final;
	virtual double GetPerimeter() const override final;

private:
	double m_x, m_y;
};

