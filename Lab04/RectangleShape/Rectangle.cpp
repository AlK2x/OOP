#include "stdafx.h"
#include "Rectangle.h"

CRectangle::CRectangle(int left, int top, int width, int height)
	:m_left(left), m_top(top), m_width(0), m_height(0)
{
	m_width = width > 0 ? width : 0;
	m_height = height > 0 ? height : 0;
	m_right = m_left + m_width;
	m_bottom = m_top + m_height;
}

int CRectangle::GetWidth() const
{
	return m_width;
}

void CRectangle::SetWidth(int width)
{
	m_width = width > 0 ? width : 0;
	m_right = m_left + m_width;
}

int CRectangle::GetHeight() const
{
	return m_height;
}

void CRectangle::SetHeight(int height)
{
	m_height = height > 0 ? height : 0;
	m_bottom = m_top + m_height;
}

int CRectangle::GetLeft() const
{
	return m_left;
}

void CRectangle::SetLeft(int left)
{
	m_left = left;
	m_right = m_left + m_width;
}

int CRectangle::GetTop() const
{
	return m_top;
}

void CRectangle::SetTop(int top)
{
	m_top = top;
	m_bottom = m_top + m_height;
}

int CRectangle::GetRight() const
{
	return m_right;
}

void CRectangle::SetRight(int right)
{
	m_right = right;
	m_left = m_right - m_width;
}

int CRectangle::GetBottom() const
{
	return m_bottom;
}

void CRectangle::SetBottom(int bottom)
{
	m_bottom = bottom;
	m_top = m_bottom - m_height;
}

int CRectangle::GetArea() const
{
	return m_width * m_height;
}

int CRectangle::GetPerimeter() const
{
	// Что делать с вырожденным прямоугольником ?
	return 2 * m_width + 2 * m_height;
}

void CRectangle::Move(int dx, int dy)
{
	SetLeft(GetLeft() + dx);
	SetTop(GetTop() + dy);
}

void CRectangle::Scale(int sx, int sy)
{
	sx = (sx > 0) ? sx : 1;
	sy = (sy > 0) ? sy : 1;
	SetWidth(GetWidth() / sx);
	SetHeight(GetHeight() / sy);
}

bool CRectangle::Intersect(CRectangle const& other)
{
	if (other.GetRight() < m_left || other.GetBottom() < m_top 
		|| other.GetTop() > m_bottom || other.GetLeft() > m_right)
	{
		SetHeight(0);
		SetWidth(0);
		return false;
	}
	else
	{
		if (m_left < other.m_left) m_left = other.m_left;
		if (m_right > other.m_right) m_right = other.m_right;
		if (m_top < other.m_top) m_top = other.m_top;
		if (m_bottom > other.m_bottom) m_bottom = other.m_bottom;

		return true;
	}
	
}