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
	T ToDelete;	
	CAVLNode<T> * TempChild = nullptr;
	CAVLNode<T> * TempFather = nullptr;
	TempChild = p_Root;
	std::cout << "Introduce el valor a eliminar: ";
	std::cin >> ToDelete;
	//Si la raiz no es un puntero nulo
	while (TempChild != nullptr)
	{
		//Se revisa si el nodo temporal tiene el valor buscado
		if (TempChild->m_Data == ToDelete)
		{
			//Si ambos hijos son punteros nulos
			if (TempChild->Left == nullptr && TempChild->Right == nullptr)
			{
				//Si no es la raiz
				if (TempFather != nullptr)
				{
					if (TempFather->Left == TempChild)
					{
						TempFather->Left = nullptr;						
					}
					else if (TempFather->Right == TempChild)
					{
						TempFather->Right = nullptr;
					}
					TempFather->Balance();
				}
				delete TempChild;
				break;
			}
			//Si solo el puntero izquierdo es nulo
			else if (TempChild->Left == nullptr && TempChild->Right != nullptr)
			{
				//Si no es la raiz
				if (TempFather != nullptr)
				{
					if (TempFather->Left == TempChild)
					{
						TempFather->Left = TempChild->Right;
					}
					else if (TempFather->Right == TempChild)
					{
						TempFather->Right = TempChild->Right;
					}
					TempChild->Right = nullptr;
					delete TempChild;
					TempFather->Balance();
					break;
				}
				//Si es la raiz
				else
				{
					p_Root = TempChild->Right;
					TempChild->Right = nullptr;
					delete TempChild;
					p_Root = p_Root->Balance();
					break;
				}
			}
			//Si solo el puntero derecho es nulo
			else if (TempChild->Left != nullptr && TempChild->Right == nullptr)
			{
				//Si no es la raiz
				if (TempFather != nullptr)
				{
					if (TempFather->Left == TempChild)
					{
						TempFather->Left = TempChild->Left;
					}
					else if (TempFather->Right == TempChild)
					{
						TempFather->Right = TempChild->Left;
					}
					TempChild->Left = nullptr;
					delete TempChild;
					TempFather->Balance();
					break;
				}
				//Si es la raiz
				else
				{
					p_Root = TempChild->Left;
					TempChild->Left = nullptr;
					delete TempChild;
					p_Root = p_Root->Balance();
					break;
				}
			}
			//Si ningun hijo es puntero nulo
			else if (TempChild->Left != nullptr && TempChild->Right != nullptr)
			{
				CAVLNode<T> * TempLeft = TempChild->Left;
				CAVLNode<T> * TempRight = TempChild->Right;
				bool Complete = false;
				while (!Complete)
				{
					while (TempLeft != nullptr)
					{
						if (TempLeft ->Right != nullptr)
						{
							if (*TempLeft->Right > *TempChild->Left && *TempLeft->Right < *TempChild->Right)
							{
								CAVLNode<T> * TempNode = TempLeft->Right;
								CAVLNode<T> * TempFatherNode = TempLeft;
								if (TempNode->Right != nullptr)
								{
									TempFatherNode = TempNode;
									TempNode = TempNode->Right;
								}
								else
								{
									TempNode->Left = TempChild->Left;
									TempNode->Right = TempChild->Right;
									TempChild->Left = nullptr;
									TempChild->Right = nullptr;
									TempFatherNode->Right = nullptr;
									if (TempFather != nullptr)
									{
										if (TempFather->Left == TempChild)
										{
											TempFather->Left = TempNode;
										}
										else if (TempFather->Right == TempChild)
										{
											TempFather->Right = TempNode;
										}
										TempFather->Balance();
									}
									else
									{
										p_Root = TempNode;
										p_Root = p_Root->Balance();
									}
									Complete = true;
									break;
								}

							}
							else
							{
								TempLeft = TempLeft->Right;
							}
						}
						else
						{
							break;
						}
					}
					if (!Complete)
					{
						while (TempRight != nullptr)
						{
							if (TempRight->Left != nullptr)
							{
								if (*TempRight->Left < *TempChild->Right && *TempRight->Left > *TempChild->Left)
								{
									CAVLNode<T> * TempNode = TempRight->Left;
									CAVLNode<T> * TempFatherNode = TempRight;
									if (TempNode->Left != nullptr)
									{
										TempFatherNode = TempNode;
										TempNode = TempNode->Left;
									}
									else
									{
										TempNode->Left = TempChild->Left;
										TempNode->Right = TempChild->Right;
										TempChild->Left = nullptr;
										TempChild->Right = nullptr;
										TempFatherNode->Left = nullptr;
										if (TempFather != nullptr)
										{
											if (TempFather->Left == TempChild)
											{
												TempFather->Left = TempNode;
											}
											else if (TempFather->Right == TempChild)
											{
												TempFather->Right = TempNode;
											}
											TempFather->Balance();
										}
										else
										{
											p_Root = TempNode;
											p_Root = p_Root->Balance();
										}
										Complete = true;
										break;
									}
								}
								else
								{
									TempRight = TempRight->Left;
								}
							}
							else
							{
								break;
							}
						}
					}
				}								
			}
		}
		//Se revisa si el dato recibido es de mayor valor
		else if (TempChild->m_Data < ToDelete)
		{
			//Si hay un valor valido hacia la derecha
			if (TempChild->Right != nullptr)
			{
				TempFather = TempChild;
				TempChild = TempChild->Right;
			}
		}
		//Se revisa en caso de ser menor
		else
		{
			//Si hay un vaor valido hacia la izquierda
			if (TempChild->Left != nullptr)
			{
				TempFather = TempChild;
				TempChild = TempChild->Left;
			}
		}
	}
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
template class CAVLTree<char>;
