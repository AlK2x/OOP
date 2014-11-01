#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CryptFile(ifstream& ifs, ofstream& ofs, char const& key)
{

}

void DecryptFile(ifstream& ifs, ofstream& ofs, char const& key)
{

}

bool ExecuteCommand(string const& command, ifstream& ifs, ofstream& ofs, char const& key)
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
		return false;
	}

	return true;
}

void PrintUsage()
{
	cout << "Usage: crypt.exe :command <input file> <output file> <key>\n";
	cout << "commands : crypt|decrypt\n";
	cout << "key: [0; 255]\n";
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

	char key = argv[4][0];

	if (!ExecuteCommand(command, inputFile, outputFile, key))
	{
		cout << "Unknown command " << command << '\n';
		PrintUsage();
		return 1;
	}
	outputFile.close();

	return 0;
}