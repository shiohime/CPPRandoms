#pragma once
#include <vector>
#include <iostream>
#include <climits>

class IncreasingTriplet
{
public:
	static bool increasingTriplet(std::vector<int>& nums);
	static void IncreasingTripletTest();
private:
	static bool increaseRecursion(std::vector<int>& nums, std::vector<int>::iterator it);
	static void printTripletTest(std::vector<int> nums);
};