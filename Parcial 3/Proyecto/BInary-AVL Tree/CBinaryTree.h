#pragma once
#include "CNode.h"
template <class T>
class CBinaryTree
{
public:

	CBinaryTree();
	CBinaryTree(CNode<T> * R);
	~CBinaryTree();

	CNode<T> * p_Root;

	void TreeInOrden();
	void TreePreOrden();
	void TreePostOrden();
	virtual void Insert(CNode<T> * & Node);
	void Delete(T ToDelete);
	virtual void RightRotate(CNode<T> * & Node);
	virtual void LeftRotate(CNode<T> * & Node);
};