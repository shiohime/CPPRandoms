#pragma once

namespace AVL
{
	template <class T>
	class AVLNode
	{
	public:
		T value;
		AVLNode<T> *left;
		AVLNode<T> *right;

		AVLNode(T value)
		{
			this->value = value;
		}
	};
}