#include "stdafx.h"
#include "Node.h"

Node::Node(int value, int pageNumber)
{
	_value = value;
	AddPageToNode(pageNumber);
}

void Node::AddPageToNode(int pageNumber)
{
	_pages.push_back(pageNumber);
}

std::ostream& operator<<(std::ostream& os, const Node& node)
{
	for (auto const& i : node._pages)
	{
		os << "Page number = " << i << " value = " << node._value << std::endl;
	}

	return os;
}