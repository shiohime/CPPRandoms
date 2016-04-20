#include "stdafx.h"
#include "AVLTree.h"

using namespace AVL;

template <class T>
bool AVLTree<T>::empty()
{
	return _root == nullptr;
}

template <class T>
void AVLTree<T>::insertValue(T nodeValue)
{
	if (empty())
	{
		AVLNode<T> *newNode = new AVLNode<T>();
		_root = newNode;
		return;
	}

	AVLNode<T> *current = _root;
	AVLNode<T> *previous = nullptr;

	while (current != nullptr)
	{
		previous = current;
		if (nodeValue > current->value)
		{
			previous = current;
			current = current->right;
		}

		else if (nodeValue < current->value)
		{
			previous = current;
			current = current->left;
		}

		else
		{
			return;
		}
	}
}

template <class T>
void AVLTree<T>::deleteValue(T nodeValue)
{

}

template <class T>
bool AVLTree<T>::containsValue(T nodeValue)
{

}

template <class T>
std::string AVLTree<T>::inorderTraversal()
{

}

template <class T>
std::string AVLTree<T>::preorderTraversal()
{

}

template <class T>
std::string AVLTree<T>::postorderTraversal()
{

}