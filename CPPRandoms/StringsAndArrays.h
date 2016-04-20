#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

namespace Book
{
	class StringsAndArrays
	{
	public:
		static bool hasAllUniqueChars(std::string const& s);
		static bool hasAllUniqueCharsNoDS(std::string const& s);
		static std::string reverseString(std::string& s);

		static void test();
	private:
		static void testAllHasUniqueChars(std::string const& s);
		static void testReverseString(std::string& s);
	};

}