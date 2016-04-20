#pragma once
#include <algorithm>
#include <vector>
#include <iostream>

namespace LongestSequence
{
	class LSeq {
	public:
		static int longest(const std::vector<int>& S);
		static void test();
	private:
		static int longestRec(const std::vector<int>& S, int pos, std::vector<int>& tabs);
		static void print(std::vector<int> S);
		static void printVec(std::vector<int> S);
	};
}