#include "CBinaryTree.h"

template<class T>
CBinaryTree<T>::CBinaryTree(){}

template<class T>
CBinaryTree<T>::CBinaryTree(CBinaryNode<T>* R)
{
	p_Root = R;
}

template <class T>
CBinaryTree<T>::~CBinaryTree(){}

template<class T>
void CBinaryTree<T>::TreeInOrden()
{
	if (p_Root != nullptr)
	{
		p_Root->InOrden();
	}
}

template<class T>
void CBinaryTree<T>::TreePreOrden()
{
	if (p_Root != nullptr)
	{
		p_Root->PreOrden();
	}
}

template<class T>
void CBinaryTree<T>::TreePostOrden()
{
	if (p_Root != nullptr)
	{
		p_Root->PostOrden();
	}
}

template<class T>
void CBinaryTree<T>::Insert(CBinaryNode<T>*& Node)
{
	if (p_Root != nullptr)
	{
		p_Root->InsertToNode(Node);
	}
	else
	{
		p_Root = Node;
	}
}

template<class T>
void CBinaryTree<T>::Delete(T ToDelete)
{
}

template class CBinaryTree<int>;