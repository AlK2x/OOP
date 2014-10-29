#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void WriteToFile(const char numBytes, const char inputChar, ofstream& ofs)
{
	ofs.write(&numBytes, sizeof(char));
	ofs.write(&inputChar, sizeof(char));
}

void PackFile(ifstream& ifs, ofstream& ofs)
{
	unsigned char numEquivalentBytes = 0;
	bool writeEndOfFile = false;

	char currentByte, previousByte;
	if (ifs.read(&previousByte, sizeof(char)))
	{
		++numEquivalentBytes;
		writeEndOfFile = true;
	}

	
	while (ifs.read(&currentByte, sizeof(char)))
	{
		writeEndOfFile = true;
		++numEquivalentBytes;

		if (currentByte != previousByte || numEquivalentBytes == 255)
		{
			WriteToFile(numEquivalentBytes, previousByte, ofs);
			writeEndOfFile = false;
			numEquivalentBytes = 0;
			previousByte = currentByte;
		}

		
	}

	if (writeEndOfFile)
	{
		WriteToFile(numEquivalentBytes, previousByte, ofs);
	}
}

void UnpackFile(ifstream& ifs, ofstream& ofs)
{
	// do another street magic
}

bool ExecuteCommand(string const& command, ifstream& ifs, ofstream& ofs)
{
	if (command == "pack")
	{
		PackFile(ifs, ofs);
	}
	else if (command == "unpack")
	{
		UnpackFile(ifs, ofs);
	}
	else
	{
		return false;
	}

	return true;
}

int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		cout << "Usage: rle.exe :command <input file> <output file>\n";
		cout << "commands : pack|unpack\n";
		return 1;
	}

	string command = argv[1];

	ifstream inputFile(argv[2], ios_base::binary);
	if (!inputFile)
	{
		cout << "Can't open file " << argv[2] << "\n";
	}

	ofstream outputFile(argv[3], ios_base::binary);
	if (!outputFile)
	{
		cout << "Can't open file " << argv[3] << "\n";
	}
	
	if (!ExecuteCommand(command, inputFile, outputFile))
	{
		cout << "Unknown command " << command << '\n';
		return 1;
	}
	outputFile.close();

	return 0;
}