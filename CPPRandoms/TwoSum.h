#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>

class twoSum
{
public:
	static std::vector<int> doTwoSum(std::vector<int>& nums, int target);
	static void TwoSumTest();
private:
	static void printTwoSum(std::vector<int> nums, int target);
};