#include "stdafx.h"
#include "LeetCode207.h"

using namespace LeetCode207;

bool LC207::canFinish(int numCourses, std::vector<std::pair<int, int>>& prerequisites)
{
	int completedCourses = 0;
	std::unordered_map<int, std::vector<int>> edgeMap;
	std::vector<int> prereqCount(numCourses, 0);
	
	for (auto const& edge : prerequisites)
	{
		if (edgeMap.find(edge.second) != edgeMap.end())
		{
			edgeMap[edge.second].push_back(edge.first);
		}
		else
		{
			edgeMap.emplace(edge.second, std::vector<int>{ edge.first });
		}
		prereqCount[edge.first]++;
	}

	std::queue<int> deleteList;
	for (int i = 0; i < prereqCount.size(); i++)
	{
		if (prereqCount[i] == 0)
		{
			deleteList.push(i);
		}
	}

	while (!deleteList.empty())
	{
		int classToComplete = deleteList.front();
		deleteList.pop();
		completedCourses++;

		for (auto const& course : edgeMap[classToComplete])
		{
			if (--prereqCount[course] <= 0)
			{
				deleteList.push(course);
			}
		}
	}
	
	return completedCourses == numCourses;
}

void LC207::test()
{
	print(2, { {1,0} });
	print(2, { {1, 0}, { 0,1 } });
	print(3, { {2, 0}, {1, 2}, {0, 1} });
	print(3, { {2, 1}, {2,0}, {1,0} });
}

void LC207::print(int numCourses, std::vector<std::pair<int, int>> prerequisites)
{
	std::cout << "NumCourses = " << numCourses << std::endl;
	std::cout << "Prerequisites = [";
	for (auto const& edge : prerequisites)
	{
		std::cout << "[" << edge.first << "," << edge.second << "] ";
	}
	std::cout << "]" << std::endl;

	std::cout << "Can be completed? " << (canFinish(numCourses, prerequisites) ? "Yes!" : "No!") << std::endl << std::endl;
}