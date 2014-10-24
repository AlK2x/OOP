#include <iostream>

using namespace std;

void FlipBits(unsigned & input)
{
	input = ((input >> 1) & 0x55) | ((input & 0x55) << 1);
	input = ((input >> 2) & 0x33) | ((input & 0x33) << 2);
	input = ((input >> 4) & 0x0f) | ((input & 0x0f) << 4);
}

int main(int argc, char * argv[])
{
	unsigned input;

	cin >> input;
	FlipBits(input);
	cout << input;

	return 0;
}