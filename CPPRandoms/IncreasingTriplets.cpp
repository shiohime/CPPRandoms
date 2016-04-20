#include "stdafx.h"
#include "IncreasingTriplet.h"

bool IncreasingTriplet::increasingTriplet(std::vector<int>& nums)
{
	int a = INT_MAX;
	int b = INT_MAX;

	for (auto const& i : nums)
	{
		if (i <= a)
		{
			a = i;
		}
		else if (i <= b)
		{
			b = i;
		}
		else
		{
			return true;
		}
	}

	return false;
}

bool increaseRecursion(std::vector<int>& nums, std::vector<int>::iterator it)
{
	if (it == nums.end())
	{
		return false;
	}
	return true;
}

void IncreasingTriplet::IncreasingTripletTest()
{
	printTripletTest({ 1, 2, 3, 4, 5 });
	printTripletTest({ 5, 4, 3, 2, 1 });
	printTripletTest({ 5, 4, 3, 4, 5 });
	printTripletTest({ 1,2  });
	printTripletTest({ 0 });
	printTripletTest({ 1, 4, 3, 5, 4, 5, 7, 8});
	printTripletTest({ 5, 1, 5, 5, 2, 5, 4 });
}

void IncreasingTriplet::printTripletTest(std::vector<int> nums)
{
	std::cout << "Input array - [";
	for (auto const& i : nums)
	{
		std::cout << i;
	}
	std::cout << "]" << std::endl;

	if (increasingTriplet(nums))
	{
		std::cout << "Increasing triplet exists!" << std::endl;
	}

	else
	{
		std::cout << "Increasing triplet doesn't exist!" << std::endl;
	}

	std::cout << std::endl;
}