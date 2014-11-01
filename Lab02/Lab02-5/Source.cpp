#include <iostream>
#include <fstream>
#include <string>

typedef void(*CipherFunction)(char& i, const unsigned char key);

using namespace std;

void CryptByte(char& i, const unsigned char key)
{
	i ^= key;
	i = (i & 0x80 >> 2) | (i & 0x60 >> 5) | (i & 0x07 << 2) | (i & 0x18 << 3);
}

void DecodeByte(char& i, const unsigned char key)
{
	i = (i & 0x20 << 2) | (i & 0x03 << 5) | (i & 0x1C >> 2) | (i & 0xC0 >> 3);
	i ^= key;
}


void ProcessFile(ifstream& ifs, ofstream& ofs, const unsigned char key, CipherFunction fn)
{
	char word;
	while (ifs.read(&word, sizeof(char)))
	{
		fn(word, key);
		ofs.write(&word, sizeof(char));
	}
}

void ExecuteCommand(string const& command, ifstream& ifs, ofstream& ofs, const unsigned char key)
{
	if (command == "crypt")
	{
		ProcessFile(ifs, ofs, key, CryptByte);
	}
	else if (command == "decrypt")
	{
		ProcessFile(ifs, ofs, key, DecodeByte);
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

	string stringKey(argv[4]);

	try
	{
		unsigned char key = ReadKey(stringKey);
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