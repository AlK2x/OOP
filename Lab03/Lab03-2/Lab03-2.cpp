#include "stdafx.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cassert>
#include "ProcessString.h"

using namespace std;

int main(int argc, char * argv[])
{
	cout << RemoveExtraSpaces("     Test    test     ") << '|' << endl;

	return 0;
}