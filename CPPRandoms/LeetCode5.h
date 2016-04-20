#pragma once
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace LeetCode5
{
	class LC5
	{
	public:
		static std::string longestPalindrome(std::string s);
		static std::string longestPalindromeSlow(std::string s);
		static void LC5Test();
	private:
		static void print(std::string s);
		static bool isPalindrome(std::string s);
		static bool isPalindromeSub(std::string s, int begin, int end, std::string& output);
	};
}