#pragma once
#include "AVLNode.h"
#include <string>
#include <iostream>

namespace AVL
{
	template <class T>
	class AVLTree
	{
	public:
		void insertValue(T nodeValue);
		void deleteValue(T nodeValue);
		bool containsValue(T nodeValue);
		inline bool empty();
		std::string inorderTraversal();
		std::string preorderTraversal();
		std::string postorderTraversal();
	private:
		AVLNode<T> *_root;
		int _depth;
	};
}