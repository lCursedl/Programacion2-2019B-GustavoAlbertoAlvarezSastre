#include "CAVLTree.h"

template <class T>
CAVLTree<T>::CAVLTree()
{
	p_Root = nullptr;
}

template <class T>
CAVLTree<T>::~CAVLTree()
{
	if (p_Root != nullptr)
	{
		delete p_Root;
	}
}

template<class T>
void CAVLTree<T>::TreeInOrden()
{
	if (p_Root != nullptr)
	{
		p_Root->InOrden();
	}
}

template<class T>
void CAVLTree<T>::TreePreOrden()
{
	if (p_Root != nullptr)
	{
		p_Root->PreOrden();
	}
}

template<class T>
void CAVLTree<T>::TreePostOrden()
{
	if (p_Root != nullptr)
	{
		p_Root->PostOrden();
	}
}

template<class T>
void CAVLTree<T>::Insert()
{
	CAVLNode<T> * InsertNode = new CAVLNode<T>();
	if (p_Root != nullptr)
	{
		p_Root->InsertToNode(InsertNode);
		p_Root = p_Root->Balance();
	}
	else
	{
		p_Root = InsertNode;
	}
}

template<class T>
void CAVLTree<T>::Delete()
{
}

template<class T>
void CAVLTree<T>::R_rotate(CAVLNode<T>* & Node)
{
	CAVLNode<T> * Pivot;
	if (Node->Left != nullptr)
	{
		Pivot = Node->Left;
		if (Pivot->Right != nullptr)
		{
			Node->Left = Pivot->Right;
		}
		else
		{
			Node->Left = nullptr;
		}
		Pivot->Right = Node;
		if (Node != p_Root)
		{
			CAVLNode<T> * Parent = p_Root;
			while (Parent != nullptr)
			{
				if (*Parent > *Node)
				{
					if (*Parent->Left == *Node)
					{
						Parent->Left = Pivot;
						break;
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
						break;
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
void CAVLTree<T>::L_rotate(CAVLNode<T>* & Node)
{
	CAVLNode<T> * Pivot;
	if (Node->Right != nullptr)
	{
		Pivot = Node->Right;
		if (Pivot->Left != nullptr)
		{
			Node->Right = Pivot->Left;
		}
		else
		{
			Node->Right = nullptr;
		}
		Pivot->Left = Node;
		
		if (Node != p_Root)
		{
			CAVLNode<T> * Parent = p_Root;
			while (Parent != nullptr)
			{
				if (*Parent > *Node)
				{
					if (*Parent->Left == *Node)
					{
						Parent->Left = Pivot;
						break;
					}
					else
					{
						Parent = Parent->Left;
					}
				}
				else
				{
					if (*Parent->Right == *Node)
					{
						Parent->Right = Pivot;
						break;
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

template class CAVLTree<int>;