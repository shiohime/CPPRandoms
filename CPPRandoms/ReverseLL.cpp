#include "stdafx.h"
#include "ReverseLL.h"

using namespace ReverseLLProblem;

Node::Node(int val)
{
	value = val;
	next = nullptr;
}

void ReverseLL::test()
{
	testVec({ 1,2,3,4 });
	testVec({ 5,3,3,3,8,9,10 });
	testVec({});
	testVec({ 0 });
	
}

void ReverseLL::testVec(std::vector<int> list)
{
	//LibPrint::printVector(list);
	Node* a = buildList(list);
	print(a);
}

Node* ReverseLL::buildList(std::vector<int>& list)
{
	Node* current = nullptr;
	Node* previous = nullptr;
	Node* start = nullptr;

	for (auto const& i : list)
	{
		current = new Node(i);
		if (previous == nullptr)
		{
			start = current;
		}
		else
		{
			previous->next = current;
		}
		previous = current;
		current = current->next;
	}
	return start;
}

void ReverseLL::print(Node* start)
{
	printRev(start);
	std::cout << std::endl;
}

void ReverseLL::printRev(Node* cur)
{
	Node* newHead = reverse(cur);
	Node* current = newHead;
	while (current != nullptr)
	{
		std::cout << current->value << " ";
		current = current->next;
	}

	cur = reverse(newHead);
}

Node* ReverseLL::reverse(Node* start)
{
	Node* current = start;
	Node* prev = nullptr;

	while (current != nullptr)
	{
		Node* temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}

	return prev;
}

void ReverseLL::printRec(Node* cur)
{
	if (cur == nullptr)
	{
		return;
	}

	printRec(cur->next);
	std::cout << cur->value << " ";
}