#pragma once
#include <stdio.h>
#include <string>

class CFile
{
public:
	CFile();

	bool Open(std::string const & filename, std::string const & regime);
	~CFile();

private:
	FILE * m_pFile;
};

