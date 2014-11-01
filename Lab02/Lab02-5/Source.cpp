#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ShuffleBits(char& i)
{
	i = (i & 0x80 >> 2) | (i & 0x60 >> 5) | (i & 0x07 << 2) | (i & 0x18 << 3);
}

void UnshuffleBits(char& i)
{
	i = (i & 0x20 << 2) | (i & 0x03 << 5) | (i & 0x1C >> 2) | (i & 0xC0 >> 3);
}


void CryptFile(ifstream& ifs, ofstream& ofs, const unsigned char key)
{
	char word;
	while (ifs.read(&word, sizeof(char)))
	{
		word ^= key;
		ShuffleBits(word);
		ofs.write(&word, sizeof(char));
	}
}

void DecryptFile(ifstream& ifs, ofstream& ofs, const unsigned char key)
{
	char word;
	while (ifs.read(&word, sizeof(char)))
	{
		UnshuffleBits(word);
		word ^= key;
		ofs.write(&word, sizeof(char));
	}
}

void ExecuteCommand(string const& command, ifstream& ifs, ofstream& ofs, const unsigned char key)
{
	if (command == "crypt")
	{
		CryptFile(ifs, ofs, key);
	}
	else if (command == "decrypt")
	{
		DecryptFile(ifs, ofs, key);
	}
	else
	{
		throw invalid_argument("Unknown command: " + command);
	}
}

void PrintUsage()
{
	cout << "Usage:     crypt.exe <command> <input file> <output file> <key>\n";
	cout << "Commands:  crypt | decrypt\n";
	cout << "Key:       [0; 255]\n";
}

bool StringToInt(string str, int & value)
{
	try
	{
		value = stoi(str);
	}
	catch (exception const&)
	{
		return false;
	}

	return true;
}

unsigned char ReadKey(string input)
{
	int val;
	if (!StringToInt(input, val) || val < 0 || val > 255)
	{
		throw invalid_argument("Invalid key: " + input);
	}

	return static_cast<unsigned char>(val);
}

int main(int argc, char* argv[])
{
	if (argc < 5)
	{
		PrintUsage();
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

	string keyString(argv[4]);

	try
	{
		unsigned char key = ReadKey(keyString);
		ExecuteCommand(command, inputFile, outputFile, key);
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << '\n';
		PrintUsage();
		return 1;
	}

	outputFile.close();

	return 0;
}