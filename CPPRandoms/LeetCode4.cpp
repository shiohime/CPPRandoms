#include "stdafx.h"
#include "LeetCode4.h"

double LC4::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
	double medianPos = (nums1.size() + nums2.size()) / 2.0;
	int high = std::ceil(medianPos);
	int low = std::floor(medianPos);
	int pos1 = 0, pos2 = 0;
	for (int i = 0; i < high; i++)
	{
		if (pos1 >= nums1.size())
		{

		}

		else if (pos2 >= nums2.size())
		{

		}

		if (nums1[pos1] > nums2[pos2])
		{

		}
	}
	

	for (int i = 0, j = 0; (i < nums1.size()) || (j < nums2.size()); i++, j++)
	{

	}

	return 0.0;
}
void LC4::LC4Test()
{

}

void LC4::print(std::vector<int>& nums1, std::vector<int>& nums2)
{

}