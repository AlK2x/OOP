#include "stdafx.h"
#include "File.h"

CFile::CFile()
	:m_pFile(nullptr)
{}

bool CFile::Open(std::string const & filename, std::string const & regime)
{
	m_pFile = fopen(filename.c_str(), regime.c_str());

	return m_pFile ? true : false;
}