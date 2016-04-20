#include "stdafx.h"
#include "LeetCode301.h"

using namespace LeetCode301;

std::vector<int> LC301::findMinHeightTrees(int n, std::vector<std::pair<int, int>>& edges)
{
	std::unordered_map<int,Node*> graph = buildGraphMap(n, edges);
	std::vector<int> MHTNodes;

	if (graph.empty()) return MHTNodes;
	MHTNodes = depthRemovingLeaves(graph);	

	for (auto const& node : graph)
	{
		delete node.second;
	}

	return MHTNodes;
}

std::vector<int> LC301::depthSlow(int n, std::vector<Node*>& graph)
{
	std::vector<int> MHTNodes;
	std::map<int, std::vector<int>*> hash;
	for (auto const& node : graph)
	{
		bool* visited = new bool[n]();
		int depth = depthFromNode(node->label, graph, visited);
		if (hash.find(depth) != hash.end())
		{
			hash[depth]->push_back(node->label);
		}
		else
		{
			std::vector<int>* nodeList = new std::vector<int>{ node->label };
			hash.emplace(depth, nodeList);
		}
		delete[] visited;
	}

	for (auto const& lowest : *(hash.begin()->second))
	{
		MHTNodes.push_back(lowest);
	}

	for (auto const& entry : hash)
	{
		delete entry.second;
	}

	return MHTNodes;
}

std::vector<int> LC301::depthRemovingLeaves(std::unordered_map<int, Node*>& graph)
{
	std::vector<int> nodeList;

	std::queue<Node*> deleteNodes;
	
	//Add all leaves to the delete queue
	for (auto const& entry : graph)
	{
		Node* node = entry.second;
		if (node->adjacentNodes.size() == 1)
		{
			deleteNodes.push(node);
		}
	}

	while (!deleteNodes.empty() && deleteNodes.size() < graph.size())
	{
		std::vector<Node*> nextDeletes;

		//Perform this wave of deletes
		while (!deleteNodes.empty())
		{
			Node* deleteTarget = deleteNodes.front();
			deleteNodes.pop();

			//Remove node from all neighbor's adjacency lists
			for (auto const& entry : deleteTarget->adjacentNodes)
			{
				Node* neighbor = entry.second;
				neighbor->adjacentNodes.erase(deleteTarget->label);

				//If the neighbor now became a leaf add it to the queue
				if (neighbor->adjacentNodes.size() == 1)
				{
					nextDeletes.push_back(neighbor);
				}
			}

			//Remove from the graph
			graph.erase(deleteTarget->label);
			//Now delete the node
			delete deleteTarget;
		}

		//Add next wave of deletes
		for (auto const& node : nextDeletes)
		{
			deleteNodes.push(node);
		}
	}

	//Add the remaining values to the MHT node list
	for (auto const& entry : graph)
	{
		nodeList.push_back(entry.first);
	}

	return nodeList;
}

int LC301::depthFromNode(int n, std::vector<Node*> graph, bool visited[])
{
	Node* current = graph.at(n);
	visited[n] = true;
	if (current->adjacentNodes.empty())
	{
		return 0;
	}

	int depth = 0;
	for (auto const& node : current->adjacentNodes)
	{
		if (!visited[node.first])
		{
			visited[node.first] = true;
			depth = std::max(depth, 1 + depthFromNode(node.first, graph, visited));
		}
	}

	return depth;
}

std::unordered_map<int, Node*> LC301::buildGraphMap(int n, std::vector<std::pair<int, int>>&edges)
{
	std::unordered_map<int,Node*> graph;
	if (n <= 0) return graph;

	//Build the node list
	for (int i = 0; i < n; i++)
	{
		graph.emplace(i, new Node(i));
	}

	//Build the adjacency list
	for (auto const& edge : edges)
	{
		Node* first = graph.at(edge.first);
		Node* second = graph.at(edge.second);
		first->adjacentNodes.emplace(edge.second, second);
		second->adjacentNodes.emplace(edge.first, first);
	}

	return graph;
}

std::vector<Node*> LC301::buildGraph(int n, std::vector<std::pair<int, int>>& edges)
{
	std::vector<Node*> graph;
	if (n <= 0) return graph;

	
	for (int i = 0; i < n; i++)
	{
		graph.push_back(new Node(i));
	}

	for (auto const& edge : edges)
	{
		Node* first = graph.at(edge.first);
		Node* second = graph.at(edge.second);
		first->adjacentNodes.emplace(edge.second,second);
		second->adjacentNodes.emplace(edge.first,first);
	}

	return graph;
}

void LC301::test()
{
	print(1, {});
	print(3, { { 1,0 },{ 1,2 }});
	print(4, { {1,0}, {1,2}, {1,3} });
	print(6, { {0, 3},{1, 3},{2, 3},{4, 3},{5, 4} });
	//
	print(6, { {0, 1},{0, 2},{0, 3},{3, 4},{4, 5} });
}

void LC301::print(int n, std::vector<std::pair<int, int>> edges)
{
	std::cout << "Vertices = " << n << std::endl;
	std::cout << "Edges = ";
	printVector(edges);
	std::cout << "Min height = ";
	std::vector<int> mht = findMinHeightTrees(n, edges);
	std::cout << "[";
	for (auto const& val : mht)
	{
		std::cout << val << " ";
	}
	std::cout << "]" << std::endl << std::endl;
}

void LC301::printVector(std::vector<std::pair<int, int>>& edges)
{
	std::cout << "[";
	for (auto const& pair : edges)
	{
		std::cout << "[" << pair.first << ", " << pair.second << "] ";
	}

	std::cout << "]" << std::endl;
}