#include "stdafx.h"
#include "Rectangle.h"
#include "Canvas.h"
#include <string>
#include <fstream>
#include <exception>
#include <iostream>
#include <iomanip>

using namespace std;

const string INITIALIZE = "Rectangle";
const string MOVE		= "Move";
const string SCALE		= "Scale";

CRectangle CreateRectangleFromFile(string filename)
{
	CRectangle rect(0, 0, 0, 0);
	ifstream ifs(filename);
	if (!ifs)
	{
		throw runtime_error("Can't open file " + filename);
	}

	string command;
	while (ifs >> command)
	{
		if (command == INITIALIZE)
		{
			int left, top, width, height;
			ifs >> left >> top >> width >> height;
			rect.SetLeft(left);
			rect.SetTop(top);
			rect.SetWidth(width);
			rect.SetHeight(height);
		}
		else if (command == MOVE)
		{
			int dx, dy;
			ifs >> dx >> dy;
			rect.Move(dx, dy);
		}
		else if (command == SCALE)
		{
			int sx, sy;
			ifs >> sx >> sy;
			rect.Scale(sx, sy);
		}
		else
		{
			throw logic_error("Unknown command " + command + " in file " + filename);
		}
	}

	return rect;
}

void PrintRectangle(CRectangle rect, string title)
{
	cout << title << ":\n";
	cout << "       Left top: ("<< rect.GetLeft() << "; " << rect.GetTop() << ")\n";
	cout << "       Size: " << rect.GetWidth() << "*" << rect.GetHeight() << "\n";
	cout << "       Right bottom: (" << rect.GetRight() << "; " << rect.GetBottom() << ")\n";
	cout << "       Area: " << rect.GetArea() << "\n";
	cout << "       Perimeter: " << rect.GetPerimeter() << "\n";
}

CRectangle IntersectRectangles(CRectangle & rect1, CRectangle & rect2)
{
	rect1.Intersect(rect2);
	return rect1;
}

void FillRectangle(CRectangle const& rect, char code, CCanvas & canvas)
{
	int left = rect.GetLeft();
	int top = rect.GetTop();

	for (unsigned y = top; y < top + rect.GetHeight(); ++y)
	{
		for (unsigned x = left; x < left + rect.GetWidth(); ++x)
		{
			canvas.SetPixel(x, y, code);
		}
	}
}

void WriteCanvasToFile(string filename, CCanvas const& canva)
{
	ofstream ost(filename);
	if (!ost)
	{
		throw runtime_error("Can't create file " + filename);
	}
	canva.Write(ost);
}

int main(int argc, char * argv[])
{
	if (argc < 3)
	{
		cout << "Usage: Rectangle <file1> <file2>\n";
		return 1;
	}

	try
	{
		CRectangle firstRect = CreateRectangleFromFile(argv[1]);
		CRectangle secondRect = CreateRectangleFromFile(argv[2]);
		CCanvas canva(100, 100);

		FillRectangle(firstRect, '+', canva);
		FillRectangle(secondRect, '-', canva);

		PrintRectangle(firstRect, "Rectangle 1");
		PrintRectangle(secondRect, "Rectangle 2");
		CRectangle intersectRectangle = IntersectRectangles(firstRect, secondRect);
		PrintRectangle(intersectRectangle, "Intersection rectangle");
		
		FillRectangle(intersectRectangle, '#', canva);
		argc >= 3 ? WriteCanvasToFile(argv[3], canva) : canva.Write(cout);
	}
	catch (logic_error const & e)
	{
		cout << e.what() << endl;
	}
	catch (runtime_error const & e)
	{
		cout << e.what() << endl;
		cout << "Programm will be closed\n";
		return 1;
	}

	return 0;
}

