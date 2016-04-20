#pragma once
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

namespace LeetCode2
{
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	class addTwoNumbers
	{
	public:
		static ListNode* addNumbers(ListNode* l1, ListNode* l2);
		static void addNumbersTest();
		static std::string printList(const ListNode* const list);
	private:
		static void print(ListNode* l1, ListNode* l2);
		static ListNode* buildList(std::vector<int> list);
	};
}