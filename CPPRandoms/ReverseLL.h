#pragma once
#include <stack>
#include <iostream>
#include <vector>
#include "LibPrint.h"

namespace ReverseLLProblem
{
	class Node
	{
	public:
		int value;
		Node* next;

		Node(int val);
	};

	class ReverseLL
	{
	public:
		static void test();
		static void testVec(std::vector<int> list);
		static Node* buildList(std::vector<int>& list);
		static Node* reverse(Node* start);
		static void print(Node* start);
		static void printRec(Node* cur);
		static void printRev(Node* cur);
	};
}