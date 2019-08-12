#include "CBinaryTree.h"

template<class T>
CBinaryTree<T>::CBinaryTree(){}

template<class T>
CBinaryTree<T>::CBinaryTree(CNode<T>* R)
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
void CBinaryTree<T>::Insert(CNode<T>*& Node)
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

template<class T>
void CBinaryTree<T>::RightRotate(CNode<T>*& Node)
{
	CNode<T> * Pivot;
	if (Node->Left != nullptr)
	{
		Pivot = Node->Left;
		if (Pivot->Right != nullptr)
		{
			Node->Left = Pivot->Right;
		}
		Pivot->Right = Node;
		if (Node != p_Root)
		{
			CNode<T> * Parent = p_Root;
			while (Parent != nullptr)
			{
				if (Parent > Node)
				{
					if (Parent->Left == Node)
					{
						Parent->Left = Pivot;
					}
					else
					{
						Parent = Parent->IzqLeft;
					}
				}
				else
				{
					if (Parent->Right == Node)
					{
						Parent->Right = Pivot;
					}
					else
					{
						Parent = Parent->Right;
					}
				}
			}
		}
		else
		{
			p_Root = Pivot;
		}
	}
}

template<class T>
void CBinaryTree<T>::LeftRotate(CNode<T>*& Node)
{
	CNode<T> * Pivot;
	if (Node->Right != nullptr)
	{
		Pivot = Node->Right;
		if (Pivot->Left != nullptr)
		{
			Node->Right = Pivot->Left;
		}
		Pivot->Left = Node;
		if (Node != p_Root)
		{
			CNode<T> * Parent = p_Root;
			while (Parent != nullptr)
			{
				if (Parent > Node)
				{
					if (Parent->Left == Node)
					{
						Parent->Left = Pivot;
					}
					else
					{
						Parent = Parent->Left;
					}
				}
				else
				{
					if (Parent->Right == Node)
					{
						Parent->Right = Pivot;
					}
					else
					{
						Parent = Parent->Right;
					}
				}
			}
		}
		else
		{
			p_Root = Pivot;
		}
	}
}