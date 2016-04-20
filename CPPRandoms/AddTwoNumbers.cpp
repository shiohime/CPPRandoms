#include "stdafx.h"
#include "AddTwoNumbers.h"

using namespace LeetCode2;

ListNode* addTwoNumbers::addNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* first = nullptr;
	ListNode* previous = nullptr;
	ListNode* temp = nullptr;
	ListNode* c1 = l1;
	ListNode* c2 = l2;
	int remainder = 0;
	while ((c1 != nullptr) || (c2 != nullptr))
	{
		int val = 0;
		if (c1 != nullptr)
		{
			val = val + c1->val;
			c1 = c1->next;
		}
		if (c2 != nullptr)
		{
			val = val + c2->val;
			c2 = c2->next;
		}
		val += remainder;
		temp = new ListNode(val % 10);
		remainder = (int)(val / 10);
		

		if (first == nullptr)
		{
			first = temp;
			previous = first;
		}
		else
		{
			previous->next = temp;
			previous = temp;
		}
	}

	if (remainder > 0)
	{
		temp = new ListNode(remainder);
		previous->next = temp;
	}

	return first;
	
	/*int i = 0;

	std::map<int, int> hash;
	while (current != nullptr)
	{
		hash.emplace(i++, current->val);
		current = current->next;
	}

	current = l2;
	int remainder = 0;
	i--;
	while (current != nullptr)
	{
		if (hash.find(i) != hash.end())
		{
			hash[i] = hash[i] + current->val + remainder;
			remainder = (int)std::floor(hash[i] / 10);
			hash[i] %= 10;
		}
		else
		{
			hash.emplace(i, current->val);
		}

		i--;
		current = current->next;
	}
	if (remainder > 0)
	{
		hash[i] = remainder;
	}


	ListNode* first = nullptr;
	ListNode* prev = nullptr;
	ListNode* temp = nullptr;
	for (auto const& cur : hash)
	{
		if (first == nullptr)
		{
			first = new ListNode(cur.second);
			prev = first;
		}
		else
		{
			temp = new ListNode(cur.second);
			prev->next = temp;
			prev = temp;
		}
	}*/
}

void addTwoNumbers::addNumbersTest()
{
	/*print(buildList({ 2,4,3 }), buildList({ 5,6,4 }));
	print(buildList({ 5 }), buildList({ 5 }));
	print(buildList({ 1,8 }), buildList({ 0 }));*/
	print(buildList({ 1 }), buildList({ 9, 9 }));
}

ListNode* addTwoNumbers::buildList(std::vector<int> list)
{
	ListNode* first = nullptr;
	ListNode* previous = nullptr;
	ListNode* temp = nullptr;
	for (auto const& i : list)
	{
		if (first == nullptr)
		{
			first = new ListNode(i);
			previous = first;
		}
		else
		{
			temp = new ListNode(i);
			previous->next = temp;
			previous = temp;
		}
	}

	return first;
}

void addTwoNumbers::print(ListNode* l1, ListNode* l2)
{
	std::cout << printList(l1) << "+" << printList(l2) << " = "  << printList(addNumbers(l1, l2)) << std::endl;
}

std::string addTwoNumbers::printList(const ListNode* const list)
{
	const ListNode* current = list;
	std::stringstream ss;
	ss << "(";
	while (current != nullptr)
	{
		ss << current->val;
		if (current->next != nullptr)
		{
			ss << "->";
		}

		current = current->next;
	}
	ss << ")" << std::endl;
	return ss.str();
}