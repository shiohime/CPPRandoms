#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#include "LibPrint.h"

class LC4
{
public:
	static double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);
	static void LC4Test();
private:
	static void print(std::vector<int>& nums1, std::vector<int>& nums2);
};