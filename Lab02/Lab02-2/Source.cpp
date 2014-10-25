#include <iostream>
#include <string>

using namespace std;

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

unsigned FlipBits(unsigned  input)
{
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

	string input = argv[1];
	int val;
	if (StringToInt(input, val))
	{
		if (val >= 0 && val <= 255)
		{
			cout << FlipBits(val) << "\n";
		}
		else
		{
			cout << "Digit " << val << " out of range [0;255].\n";
			return 1;
		}
	}
	else
	{
		cout << "Value '" << argv[1] << "' not a digit from 0 to 255.\n";
		return 1;
	}

	return 0;
}