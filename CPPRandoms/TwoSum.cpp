#include "stdafx.h"
#include "TwoSum.h"

std::vector<int> twoSum::doTwoSum(std::vector<int>& nums, int target)
{
	std::unordered_map<int, int> numMap;
	for (int i = 0; i < nums.size(); i++)
	{
		int numToFind = target - nums[i];
		if (numMap.find(numToFind) != numMap.end())
		{
			return{ numMap[numToFind], i };
		}

		numMap.emplace(nums[i], i);
	}

	return{};
}

void twoSum::TwoSumTest()
{
	printTwoSum({ 3,2,4 }, 6);
}

void twoSum::printTwoSum(std::vector<int> nums, int target)
{
	std::cout << "input vector - ";
	for (auto const& i : nums)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl << "target = " << target << std::endl;
	std::vector<int> out = doTwoSum(nums, target);
	std::cout << "output vector - ";
	for (auto const& i : out)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}