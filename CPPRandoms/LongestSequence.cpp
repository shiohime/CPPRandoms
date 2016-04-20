#include "stdafx.h"
#include "LongestSequence.h"

using namespace LongestSequence;

int LSeq::longest(const std::vector<int>& S)
{
	if (S.empty()) return 0;

	int max = 0;
	std::vector<int> tabs(S.size());
	for (int i = 0; i < S.size(); i++)
	{
		max = std::max(max, longestRec(S, i, tabs));
	}

	return max;
}

int LSeq::longestRec(const std::vector<int>& S, int pos, std::vector<int>& tabs)
{
	if (S.empty()) {
		return 0;
	}

	//if we have tabulated this position just return that
	if (tabs[pos] > 0)
	{
		return tabs[pos];
	}
	
	//Once we hit the end of the list the base case is 1
	if (pos == S.size() - 1) {
		tabs[pos] = 1;
		return 1;
	}

	int max = 1;


	//Check current position against the remainder of the list
	for (int i = pos+1; i < S.size(); i++)
	{
		if (S[i] > S[pos])
		{
			//If we've already tabulated this, then the LIS from pos is 1 (pos) + the LIS from i
			if (tabs[i] > 0)
			{
				max = std::max(max, 1 + tabs[i]);
			}
			//Otherwise it's 1 + the LIS from i (that we need to calculate)
			else
			{
				max = std::max(max, 1 + longestRec(S, i, tabs));
			}
		}
	}
	
	tabs[pos] = max;
	return max;
}

void LSeq::test()
{
	print({ 10, 9, 2, 5, 3, 7, 101, 18 });
	/*print({ 3,1,2 });
	print({1,2 });
	print({ 2,1 });
	print({ 2,1,4 });
	print({ 4,3,1,2,7,4,8,9 });*/
}

void LSeq::print(std::vector<int> S)
{
	std::cout << "Input = ";
	printVec(S);
	std::vector<int> x{};
	std::cout << "Longest sequence length = " << longest(S) << std::endl;


}

void LSeq::printVec(std::vector<int> S)
{
	std::cout << "[";
	for (auto const& i : S)
	{
		std::cout << i << " ";
	}

	std::cout << "]" << std::endl;
}