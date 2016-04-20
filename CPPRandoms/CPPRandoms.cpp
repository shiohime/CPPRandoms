// CPPRandoms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BST.h"
#include "Node.h"
#include "StringTesting.h"
#include "CrossingPaths.h"
#include "IncreasingTriplet.h"
#include "TwoSum.h"
#include "AddTwoNumbers.h"
#include "LeetCode3.h"
#include "ReverseLL.h"
#include "LeetCode5.h"
#include "LongestSequence.h"
#include "StringsAndArrays.h"
#include "LeetCode301.h"
#include "LeetCode207.h"

void BSTTest();
std::string removeRepeatingCharacters(std::string input);
void PathTest();
void PrintPathTest(std::vector<int> test);

int main()
{
	LeetCode207::LC207::test();

	std::string x;
	std::cin >> x;
    return 0;
}

void PathTest()
{
	//PrintPathTest({ 2, 1, 1, 2 });
	//PrintPathTest({ 1, 2, 3, 4 });
	PrintPathTest({ 1, 1, 1, 1 });
	
}

void PrintPathTest(std::vector<int> test)
{
	std::cout << "Vector: ";
	for (auto const& i : test)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	if (CrossingPaths::DoPathsCross(test))
	{
		std::cout << "Path crosses!" << std::endl << std::endl;
	}

	else
	{
		std::cout << "Path doesn't cross!" << std::endl << std::endl;
	}
}

void BSTTest()
{
	BST* bst = new BST();
	bst->AddPage(8,1);
	bst->AddPage(-5,2);
	bst->AddPage(3,3);
	bst->AddPage(9, 4);
	bst->AddPage(9, 5);
	bst->AddPage(6, 6);
	bst->AddPage(11, 7);
	bst->AddPage(8, 8);

	bst->FindBestPath();
}

