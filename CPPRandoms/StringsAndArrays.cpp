#include "stdafx.h"
#include "StringsAndArrays.h"

using namespace Book;

bool StringsAndArrays::hasAllUniqueChars(std::string const& s)
{
	std::unordered_map<char, bool> hash;
	for (auto const& c : s) {
		if (hash.find(c) != hash.end())
		{
			return false;
		}
		hash.emplace(c, true);
	}

	return true;
}

bool StringsAndArrays::hasAllUniqueCharsNoDS(std::string const& s)
{
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = i + 1; j < s.length(); j++)
		{
			if (s[i] == s[j])
			{
				return false;
			}
		}
	}

	return true;
}

std::string StringsAndArrays::reverseString(std::string& s)
{
	int start = 0;
	int end = s.length() - 1;
	while (start < end)
	{
		char temp = s[start];
		s[start++] = s[end];
		s[end--] = temp;
	}

	return s;
}

void StringsAndArrays::test()
{
	std::string test = "abcde";
	testReverseString(test);
	test = "abcd";
	testReverseString(test);
	test = "";
	testReverseString(test);
	test = "bdertb";
	testReverseString(test);
	test = "abcdee";
	testReverseString(test);
}

void StringsAndArrays::testAllHasUniqueChars(std::string const& s)
{
	std::cout << "Input = """ << s << std::endl;
	std::cout << "Has all unique characters - DS? " << hasAllUniqueChars(s) << std::endl;
	std::cout << "Has all unique characters - noDS? " << hasAllUniqueCharsNoDS(s) << std::endl;
}

void StringsAndArrays::testReverseString(std::string& s)
{
	std::cout << "Input = """ << s << """" << std::endl;
	std::cout << "Reverse = """ << reverseString(s) << """" << std::endl;
}