#include "stdafx.h"
#include "Canvas.h"

CCanvas::CCanvas(unsigned width, unsigned height)
	:m_width(width), m_height(height)
{
	m_canvas.assign(m_height, std::vector<char>(m_width, ' '));
}

unsigned CCanvas::GetWidth() const
{
	return m_width;
}

unsigned CCanvas::GetHeight() const
{
	return m_height;
}

char CCanvas::GetPixel(int x, int y) const
{
	if (!CanvaHasPixel(x, y))
	{
		return ' ';
	}
	return m_canvas[y][x];
}

void CCanvas::SetPixel(int x, int y, char code)
{
	if (CanvaHasPixel(x, y) && code > ' ' - 1)
	{
		m_canvas[y][x] = code;
	}
}

void CCanvas::Clear(char code)
{
	if (code > ' ' - 1)
	{
		for (auto& canvaRow : m_canvas)
		{
			std::fill(canvaRow.begin(), canvaRow.end(), code);
		}
	}
}

void CCanvas::Write(std::ostream & ostream) const
{
	for (auto& canvaRow : m_canvas)
	{
		std::ostream_iterator<char> oIt(ostream);
		copy(canvaRow.begin(), canvaRow.end(), oIt);
		ostream << '\n';
	}
}

bool CCanvas::CanvaHasPixel(unsigned x, unsigned y) const
{
	return !(x >= m_width || x < 0 || y < 0 || y >= m_height);
}
