#pragma once

#include "stdafx.h"
#include <string>
#include <map>
#include <iostream>

typedef std::map<std::string, int> stringMap;

stringMap ReadStringsFromStream(std::istream& ist);
void PrintWordFriquency(stringMap wordsMap);