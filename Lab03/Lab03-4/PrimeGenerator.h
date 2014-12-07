#pragma once

#include <set>
#include <vector>
#include <iostream>

bool IsPrime(unsigned number);
std::set<int> GeneratePrimeNumersSet(int upperBound);
void PrintSet(std::set<int> primeSet);