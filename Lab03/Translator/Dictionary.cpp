#include "stdafx.h"
#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary(std::istream & ist)
{
	string fileLine;
	while (getline(ist, fileLine))
	{
		string word, translation;
		GetWordAndTranslation(fileLine, word, translation);
		m_dictionary[word] = translation;
	}
}

bool Dictionary::GetWordAndTranslation(string line, string & word, string & translation)
{
	size_t pos = line.find(']');
	word = line.substr(1, pos);
	translation = line.substr(pos + 1, line.size());

	return true;
}

string Dictionary::GetTranslation(string word)
{
	auto wordIt = m_dictionary.find(word);
	return (wordIt == m_dictionary.end()) ? "" : wordIt->second;
}