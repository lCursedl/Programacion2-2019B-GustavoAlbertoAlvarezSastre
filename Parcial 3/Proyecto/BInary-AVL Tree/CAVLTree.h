#pragma once
#include "CAVLNode.h"
template <class T>
class CAVLTree
{
public:
	CAVLTree();
	~CAVLTree();

	CAVLNode<T> * p_Root; 

	void TreeInOrden();
	void TreePreOrden();
	void TreePostOrden();
	void Insert();
	void Delete();
	void DeleteNode(T ToDelete);
	void R_rotate(CAVLNode<T>*&Node);
	void L_rotate(CAVLNode<T>*&Node);
};