#pragma once
#include <vector>
#include <utility>
#include <iostream>
#include <unordered_map>
#include <queue>

namespace LeetCode207 
{
	class LC207
	{
	public:
		static bool canFinish(int numCourses, std::vector<std::pair<int, int>>& prerequisites);
		static void test();
	private:
		static void print(int numCourses, std::vector<std::pair<int, int>> prerequisites);
	};
}