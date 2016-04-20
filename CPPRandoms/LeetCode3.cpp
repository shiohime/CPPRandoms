#include "stdafx.h"
#include "LeetCode3.h"

using namespace LeetCode3;

int LC3::lengthOfLongestSubstring(std::string s)
{
	std::unordered_map<char, int> charMap;
	int size = 0;
	
	for (int i = 0, j = 0; i < s.length(); i++)
	{
		char c = s[i];
		//If this character repeated, the size is going to be the max of whatever is in size and the size of the current substring defined
		if (charMap.find(c) != charMap.end())
		{
			j = std::max(j, charMap[c] + 1);
		}

		//Store the current character and the position of said character
		charMap[c] = i;
		size = std::max(size, i - j + 1);
	}

	return size;
}

void LC3::LC3Test()
{
	print("abcabcbb");
	print("bbbbb");
	print("c");
	print("dvdf");
}

void LC3::print(std::string s)
{
	std::cout << "Input string = " << s << "  size = " << lengthOfLongestSubstring(s) << std::endl;
}