#pragma once
#include <ostream>
#include <vector>
#include <iterator>
#include <algorithm>

class CCanvas
{
public:
	CCanvas(unsigned width, unsigned height);

	unsigned GetWidth() const;
	unsigned GetHeight() const;
	void Clear(char code = ' ');
	void SetPixel(int x, int y, char code);
	char GetPixel(int x, int y) const;
	void Write(std::ostream & ostream)const;
private:
	typedef std::vector<std::vector<char>> Canvas;

	bool CanvaHasPixel(unsigned x, unsigned y) const;

	unsigned m_width;
	unsigned m_height;
	Canvas m_canvas;
};

