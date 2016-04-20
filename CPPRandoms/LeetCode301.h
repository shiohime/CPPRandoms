#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>

namespace LeetCode301
{
	class Node
	{
	public:
		std::unordered_map<int,Node*> adjacentNodes;
		int label;

		Node(int label) {
			this->label = label;
		}
	};

	class LC301
	{
	public:
		static std::vector<int> findMinHeightTrees(int n, std::vector<std::pair<int, int>>& edges);
		static void test();
	private:
		static std::vector<Node*> buildGraph(int n, std::vector<std::pair<int, int>>& edges);
		static std::unordered_map<int, Node*> buildGraphMap(int n, std::vector<std::pair<int, int>>&edges);
		static std::vector<int> depthSlow(int n, std::vector<Node*>& graph);
		static int depthFromNode(int n, std::vector<Node*> graph, bool visited[]);
		static std::vector<int> depthRemovingLeaves(std::unordered_map<int, Node*>& graph);
		static void print(int n, std::vector<std::pair<int, int>> edges);
		static void printVector(std::vector<std::pair<int, int>>& edges);
	};
}