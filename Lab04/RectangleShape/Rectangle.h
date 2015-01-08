#pragma once
class CRectangle
{
public:
	CRectangle(int left, int top, int width, int height);

	int GetWidth() const;
	void SetWidth(int width);

	int GetHeight() const;
	void SetHeight(int height);

	int GetLeft() const;
	void SetLeft(int left);

	int GetTop() const;
	void SetTop(int top);

	int GetRight() const;
	void SetRight(int right);

	int GetBottom() const;
	void SetBottom(int bottom);

	int GetArea() const;
	int GetPerimeter() const;

	void Move(int dx, int dy);
	void Scale(int sx, int sy);
	bool Intersect(CRectangle const& other);

private:
	int m_width;
	int m_height;
	int m_left;
	int m_top;
	int m_bottom;
	int m_right;
};

