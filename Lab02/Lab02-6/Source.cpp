#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

enum class SquareState
{
	EMPTY = ' ',
	FULL = '.',
	WALL = '#',
	START = 'O'
};

struct Maze
{
	vector<vector<char>> field;
};

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
				case ' ':
					mazeLine.push_back(squareState);
					break;
				case '#':
					mazeLine.push_back(squareState);
					break;
				case 'O':
					mazeLine.push_back(squareState);
					break;
				default:
					break;
				}
			}
		}
		m.field.push_back(mazeLine);
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

	Maze maze;
	emptyMazeFile >> maze;
	filledMazeFile << maze;

	return 0;
}