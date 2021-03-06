#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

const char FILLED = '.';
const char EMPTY = ' ';
const char WALL = '#';
const char START_POINT = 'O';

struct Point
{
	int x, y;
	Point(int x, int y) : x(x), y(y) {}
};

struct Maze
{
	vector<vector<char>> field;
	vector<Point> startPoints;
};

void FillCellsAroundPoint(Maze& maze, Point const& point)
{
	int x = point.x;
	int y = point.y;
	size_t yMax = maze.field.size() - 1;
	try
	{
		if (maze.field.at(x + 1).at(y) == EMPTY)
		{
			maze.field.at(x + 1).at(y) = FILLED;
			FillCellsAroundPoint(maze, Point(x + 1, y));
		}

		if (maze.field.at(x - 1).at(y) == EMPTY)
		{
			maze.field.at(x - 1).at(y) = FILLED;
			FillCellsAroundPoint(maze, Point(x - 1, y));
		}

		if (maze.field.at(x).at(y + 1) == EMPTY)
		{
			maze.field.at(x).at(y + 1) = FILLED;
			FillCellsAroundPoint(maze, Point(x, y + 1));
		}

		if (maze.field.at(x).at(y - 1) == EMPTY)
		{
			maze.field.at(x).at(y - 1) = FILLED;
			FillCellsAroundPoint(maze, Point(x, y - 1));
		}
	}
	catch (...)
	{
		throw runtime_error("invalid maze");
	}
}

void FillMaze(Maze& maze)
{
	for (Point startPoint : maze.startPoints)
	{
		FillCellsAroundPoint(maze, startPoint);
	}
}

ostream& operator<< (ostream& os, Maze const& maze)
{
	for (size_t row = 0; row < maze.field.size(); ++row)
	{
		for (size_t col = 0; col < maze.field[row].size(); ++col)
		{
			os << maze.field[row][col];
		}
		os << '\n';
	}
	return os;
}

istream& operator>> (istream& is, Maze& m)
{
	string line;
	int row = 0;
	while (getline(is, line))
	{
		vector<char> mazeLine;
		if (!line.empty())
		{
			for (size_t col = 0; col < line.size(); ++col)
			{
				char squareState = line[col];
				switch (squareState)
				{
				case EMPTY:
					mazeLine.push_back(squareState);
					break;
				case WALL:
					mazeLine.push_back(squareState);
					break;
				case START_POINT:
					mazeLine.push_back(squareState);
					m.startPoints.push_back(Point(row, col));
					break;
				default:
					break;
				}
			}
		}
		m.field.push_back(mazeLine);
		++row;
	}

	return is;
}

void PrintUsage()
{
	cout << "Usage:     fill.exe <input file> <output file>\n";
}

int main(int argc, char * argv[])
{
	if (argc < 3)
	{
		PrintUsage();
		return 1;
	}

	ifstream emptyMazeFile(argv[1], ios_base::binary);
	if (!emptyMazeFile)
	{
		cout << "Can't open file " << argv[2] << "\n";
		return 1;
	}

	ofstream filledMazeFile(argv[2], ios_base::binary);
	if (!filledMazeFile)
	{
		cout << "Can't open file " << argv[3] << "\n";
		return 1;
	}

	try
	{
		Maze maze;
		emptyMazeFile >> maze;
		FillMaze(maze);
		filledMazeFile << maze;
	}
	catch (exception const& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}