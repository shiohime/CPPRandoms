#pragma once
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

namespace LeetCode3
{
	class LC3
	{
	public:
		static int lengthOfLongestSubstring(std::string s);
		static void LC3Test();
	private:
		static void print(std::string s);
	};
}