#pragma once
#include "CBinaryNode.h"
template <class T>
class CBinaryTree
{
public:

	CBinaryTree();
	CBinaryTree(CBinaryNode<T> * R);
	~CBinaryTree();

	CBinaryNode<T> * p_Root;

	void TreeInOrden();
	void TreePreOrden();
	void TreePostOrden();
	void Insert();
	void Delete();
};