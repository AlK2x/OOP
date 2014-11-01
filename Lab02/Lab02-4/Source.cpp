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

	char currentByte, previousByte;
	if (ifs.read(&previousByte, sizeof(char)))
	{
		++numEquivalentBytes;
	}

	while (ifs.read(&currentByte, sizeof(char)))
	{
		
		if (currentByte != previousByte || numEquivalentBytes == 255)
		{
			WriteToFile(numEquivalentBytes, previousByte, ofs);
			numEquivalentBytes = 0;
			previousByte = currentByte;
		}

		++numEquivalentBytes;
	}

	if (numEquivalentBytes != 0 && previousByte == currentByte)
	{
		WriteToFile(numEquivalentBytes, previousByte, ofs);
	}
}

void UnpackFile(ifstream& ifs, ofstream& ofs)
{
	char numOfSymbols, symbol;

	while (ifs.read(&numOfSymbols, sizeof(char)))
	{
		if (numOfSymbols == 0)
		{
			throw runtime_error("Corrypted file. Try to print zero number chars");
		}

		if (ifs.read(&symbol, sizeof(char)))
		{
			while (numOfSymbols--)
			{
				ofs.write(&symbol, sizeof(char));
			}
		}
		else
		{
			throw runtime_error("Corrypted file. Odd file length.");
		}
		
	}
}

void ExecuteCommand(string const& command, ifstream& ifs, ofstream& ofs)
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
		throw invalid_argument("Unknown command: " + command);
	}
}

void PrintUsage()
{
	cout << "Usage: rle.exe :command <input file> <output file>\n";
	cout << "commands : pack|unpack\n";
}

int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		PrintUsage();
		return 1;
	}

	string command = argv[1];

	ifstream inputFile(argv[2], ios_base::binary);
	if (!inputFile)
	{
		cout << "Can't open file " << argv[2] << "\n";
		return 1;
	}

	ofstream outputFile(argv[3], ios_base::binary);
	if (!outputFile)
	{
		cout << "Can't open file " << argv[3] << "\n";
		return 1;
	}
	
	try
	{
		ExecuteCommand(command, inputFile, outputFile);
	}
	catch (exception& e)
	{
		cout << e.what() << '\n';
		PrintUsage();
		outputFile.close();
		return 1;
	}

	outputFile.close();

	return 0;
}