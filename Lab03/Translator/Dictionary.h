#pragma once
#include <map>
#include <string>
#include <istream>
#include <fstream>

typedef std::map<std::string, std::string> dictionary_t;

class Dictionary
{
public:
	Dictionary(std::istream &);
	std::string GetTranslation(std::string word);

private:

	bool GetWordAndTranslation(std::string line, std::string & word, std::string & translation);

	dictionary_t m_dictionary;
	dictionary_t m_new_words;
	size_t m_startDictionarySize;
};
