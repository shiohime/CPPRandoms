#include "stdafx.h"
#include "LeetCode5.h"
using namespace LeetCode5;

//class LC5
//{
//public:
//	static std::string longestPalindrome(std::string s);
//	static void print();
//private:
//	static void printSolution(std::string s);
//	static bool isPalindrome(std::string s);
//	static bool isPalindromeSub(std::string s, int begin, int end);
//};

std::string LC5::longestPalindrome(std::string s)
{
	if (s.empty())
	{
		return "";
	}

	if (s.length() == 1)
	{
		return s;
	}

	int maxLength = 0;
	std::string maxString;
	/*for (int i = 0; i < s.length(); i++)
	{

	}*/

	return "";
}

std::string LC5::longestPalindromeSlow(std::string s)
{
	int max = 0;
	std::string maxPal = "";
	std::unordered_map<char, std::vector<int>*> hash;

	for (int i = 0; i < s.length(); i++)
	{
		if (hash.find(s[i]) == hash.end())
		{
			hash.emplace(s[i], new std::vector<int>{ i });
		}

		else
		{
			for (auto const& pos : *hash[s[i]])
			{
				if (i - pos > max)
				{
					std::string pal = s.substr(pos, i-pos+1);
					if (isPalindrome(pal))
					{
						max = i - pos;
						maxPal = pal;
						break;
					}
				}
			}
			hash[s[i]]->push_back(i);
		}
	}

	return maxPal;
}

void LC5::LC5Test()
{
	print("abcdefgfed");
	print("aaa");
	print("");
	print("derpderpprazc");
}

void LC5::print(std::string s)
{
	std::cout << "Input = """ << s << """" << std::endl;
	std::cout << "Longest palindrome = """ << longestPalindrome(s) << """" << std::endl;
}

bool LC5::isPalindrome(std::string s)
{
	int start = 0;
	int end = s.length() - 1;
	while (start < end)
	{
		if (s[start++] != s[end--])
		{
			return false;
		}
	}

	return true;

}

bool LC5::isPalindromeSub(std::string s, int begin, int end, std::string& output)
{
	return isPalindrome(s.substr(begin, end));
}