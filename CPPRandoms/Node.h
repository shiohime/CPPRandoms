#pragma once
#include <list>
#include <iostream>

class Node
{
public:
	int _value;
	Node* _left;
	Node* _right;

	void AddPageToNode(int pageNumber);
	friend std::ostream& operator<<(std::ostream& os, const Node& node);
	Node(int value, int pageNumber);
private:
	std::list<int> _pages;
};