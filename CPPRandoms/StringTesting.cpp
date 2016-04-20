#include "stdafx.h"
#include "StringTesting.h"

void StringTesting::removeRepeatingCharactersTest()
{
	removeSingleTest("abcdefgabcdefg");
	removeSingleTest("aabbccdd");
	removeSingleTest("bb");
	removeSingleTest("abcd");
	removeSingleTest("cbacdcbc");
}

void StringTesting::removeSingleTest(std::string input)
{
	std::cout << "Input: """ << input << """\nOutput: """ << removeRepeatingCharacters(input) << std::endl;
}

std::string StringTesting::removeRepeatingCharacters(std::string input)
{
	std::map<char, int> charMap{};
	for (auto const& ch : input)
	{
		std::map<char, int>::iterator it = charMap.find(ch);
		if (it != charMap.end())
		{
			it->second++;
			continue;
		}

		charMap.emplace(ch, 1);
	}

	std::string output = "";
	for (auto const& ch : input)
	{
		//Decrement the count for the character in our map
		std::map<char, int>::iterator headIt = charMap.find(ch);
		if (headIt != charMap.end())
		{
			headIt->second--;
		}

		//if the character's already part of the output we can skip it
		std::size_t found = output.find(ch);
		if (found != std::string::npos)
		{
			continue;
		}

		//Otherwise, let's try to see if it's less than the character at the end of the string, and if so we need to pop it
		while ((output.length() > 0) && (ch < output.back()) && ((charMap.find(output.back())->second)))
		{
			output.pop_back();
		}

		output.push_back(ch);
	}

	return output;	
}