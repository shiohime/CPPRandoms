#pragma once
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>

class StringTesting
{
public:
	static std::string removeRepeatingCharacters(std::string input);
	static void removeRepeatingCharactersTest();
private:
	static void removeSingleTest(std::string input);
};