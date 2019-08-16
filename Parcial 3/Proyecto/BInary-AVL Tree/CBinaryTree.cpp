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
void CBinaryTree<T>::Insert()
{
	CBinaryNode<T> * Node = new CBinaryNode<T>();
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
void CBinaryTree<T>::Delete()
{
	
		T ToDelete;
		CBinaryNode<T> * TempChild = nullptr;
		CBinaryNode<T> * TempFather = nullptr;
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
					
						break;
					}
					//Si es la raiz
					else
					{
						p_Root = TempChild->Right;
						TempChild->Right = nullptr;
						delete TempChild;
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
						
						break;
					}
					//Si es la raiz
					else
					{
						p_Root = TempChild->Left;
						TempChild->Left = nullptr;
						delete TempChild;
					
						break;
					}
				}
				//Si ningun hijo es puntero nulo
				else if (TempChild->Left != nullptr && TempChild->Right != nullptr)
				{
					CBinaryNode<T> * TempLeft = TempChild->Left;
					CBinaryNode<T> * TempRight = TempChild->Right;
					bool Complete = false;
					while (!Complete)
					{
						while (TempLeft != nullptr)
						{
							if (TempLeft->Right != nullptr)
							{
								if (*TempLeft->Right > *TempChild->Left && *TempLeft->Right < *TempChild->Right)
								{
									CBinaryNode<T> * TempNode = TempLeft->Right;
									CBinaryNode<T> * TempFatherNode = TempLeft;
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
											
										}
										else
										{
											p_Root = TempNode;
											
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
										CBinaryNode<T> * TempNode = TempRight->Left;
										CBinaryNode<T> * TempFatherNode = TempRight;
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
												
											}
											else
											{
												p_Root = TempNode;
												
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

template class CBinaryTree<int>;
template class CBinaryTree<char>;