#include "stdafx.h"
#include "BST.h"

void BST::AddPage(int value, int pageNumber)
{
	if (_head == nullptr)
	{
		_head = new Node(value, pageNumber);
		return;
	}

	Node* current = _head;
	Node* previous = nullptr;
	while (current != nullptr)
	{
		previous = current;
		if (current->_value > value)
		{
			current = current->_left;
		}
		else if (current->_value < value)
		{
			current = current->_right;
		}
		else
		{
			current->AddPageToNode(pageNumber);
			return;
		}
	}

	Node* newNode = new Node(value, pageNumber);
	
	if (previous->_value > value)
	{
		previous->_left = newNode;
	}
	else
	{
		previous->_right = newNode;
	}
}

void BST::FindBestPath()
{
	Node* current = _head;
	while (current != nullptr)
	{
		std::cout << *current;
		current = current->_right;
	}
}

BST::BST()
{

}