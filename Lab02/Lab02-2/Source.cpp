#include <iostream>
#include <string>

using namespace std;

unsigned FlipBits(unsigned  input)
{
	if (input < 0 || input > 255)
	{
		throw invalid_argument("Digit out of range: [0;255].\n");
	}

	input = ((input >> 1) & 0x55) | ((input & 0x55) << 1);
	input = ((input >> 2) & 0x33) | ((input & 0x33) << 2);
	input = ((input >> 4) & 0x0f) | ((input & 0x0f) << 4);

	return input;
}

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		cout << "Input: flipbyte.exe <integer from 0 to 255>\n";
		return 1;
	}

	string input(argv[1]);
	
	try
	{
		int val = stoi(input);
		cout << FlipBits(val) << '\n';
	}
	catch (invalid_argument const& e)
	{
		cout << e.what();
		return 1;
	}

	return 0;
}