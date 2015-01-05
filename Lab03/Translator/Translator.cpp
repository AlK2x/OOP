#include "stdafx.h"
#include "Dictionary.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Usage: Translation <dictionary filename>" << endl;
		return 1;
	}

	ifstream ifs(argv[1]);
	if (!ifs.is_open())
	{
		cout << "Can't read dictionary file" << endl;
		return 1;
	}


	
	return 0;
}

