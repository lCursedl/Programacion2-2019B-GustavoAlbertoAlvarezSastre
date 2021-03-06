#include "CTree.h"

template<class T>
CTree<T>::CTree()
{
	Root = nullptr;
}

template<class T>
CTree<T>::CTree(CUser<T> * R)
{
	Root = R;
}

template<class T>
CTree<T>::~CTree()
{
	if (Root != nullptr)
	{
		delete Root;
	}
}

template<class T>
void CTree<T>::TreeInOrden()
{
	if (Root != nullptr)
	{
		Root->InOrden();
	}
}

template<class T>
void CTree<T>::TreePreOrden()
{
	if (Root != nullptr)
	{
		Root->PreOrden();
	}
}

template<class T>
void CTree<T>::TreePostOrden()
{
	if (Root != nullptr)
	{
		Root->PostOrden();
	}
}

template<class T>
void CTree<T>::Insert(CUser<T> * & Node)
{
	//Se revisa si la raiz del arbol tiene algun elemento almacenado
	if (Root != nullptr)
	{
		//De estarlo, se pasa el nodo a la raiz para que busque donde almacenarlo
		Root->InsertToNode(Node);
	}
	else
	{
		//De lo contrario, se almacena directamente en la raiz
		Root = Node;
	}
}

template<class T>
void CTree<T>::Delete(T ToDelete)
{
	CUser<T> * TempChild = nullptr;
	CUser<T> * TempFather = nullptr;
	TempChild = Root;
	//Si la raiz no es un puntero nulo
	while (TempChild != nullptr)
	{
		//Se revisa si el nodo temporal tiene el valor buscado
		if (TempChild->Data == ToDelete)
		{
			//Si ambos hijos son punteros nulos
			if (TempChild->Izq == nullptr && TempChild->Der == nullptr)
			{
				//Si no es la raiz
				if (TempFather != nullptr)
				{
					if (TempFather->Izq == TempChild)
					{
						TempFather->Izq = nullptr;
					}
					else if (TempFather->Der == TempChild)
					{
						TempFather->Der = nullptr;
					}
				}
				delete TempChild;
				break;
			}
			//Si solo el puntero izquierdo es nulo
			else if (TempChild->Izq == nullptr && TempChild->Der != nullptr)
			{
				//Si no es la raiz
				if (TempFather != nullptr)
				{
					if (TempFather->Izq == TempChild)
					{
						TempFather->Izq = TempChild->Der;						
					}
					else if (TempFather->Der == TempChild)
					{
						TempFather->Der = TempChild->Der;
					}
					TempChild->Der = nullptr;
					delete TempChild;
				}
				//Si es la raiz
				else
				{

				}
			}
			//Si solo el puntero derecho es nulo
			else if (TempChild->Izq != nullptr && TempChild->Der == nullptr)
			{
				//Si no es la raiz
				if (TempFather != nullptr)
				{
					if (TempFather->Izq == TempChild)
					{
						TempFather->Izq = TempChild->Izq;
					}
					else if (TempFather->Der == TempChild)
					{
						TempFather->Der = TempChild->Izq;
					}
					TempChild->Izq = nullptr;
					delete TempChild;
				}
				//Si es la raiz
				else
				{

				}
			}
			//Si ningun hijo es puntero nulo
			else if (TempChild->Izq != nullptr && TempChild->Der != nullptr)
			{

			}
		}
		//Se revisa si el dato recibido es de mayor valor
		else if (TempChild->Data < ToDelete)
		{
			//Si hay un valor valido hacia la derecha
			if (TempChild->Der != nullptr)
			{
				TempFather = TempChild;
				TempChild = TempChild->Der;
			}
		}
		//Se revisa en caso de ser menor
		else
		{
			//Si hay un vaor valido hacia la izquierda
			if (TempChild->Izq != nullptr)
			{
				TempFather = TempChild;
				TempChild = TempChild->Izq;
			}
		}
	}
}

template<class T>
void CTree<T>::RightRotate(CUser<T> * & Node)
{
	CUser<T> * Pivot;
	if (Node->Izq != nullptr)
	{
		Pivot = Node->Izq;
		if (Pivot->Der != nullptr)
		{
			Node->Izq = Pivot->Der;
		}
		Pivot->Der = Node;
		if (*Node != *Root)
		{
			CUser<T> * Parent = Root;
			while (Parent != nullptr)
			{
				if (Parent > Node)
				{
					if (Parent->Izq == Node)
					{
						Parent->Izq = Pivot;
					}
					else
					{
						Parent = Parent->Izq;
					}
				}
				else
				{
					if (Parent->Der == Node)
					{
						Parent->Der = Pivot;
					}
					else
					{
						Parent = Parent->Der;
					}
				}
			}
		}
	}
}

template<class T>
void CTree<T>::LeftRotate(CUser<T> * & Node)
{
	CUser<T> * Pivot;
	if (Node->Der != nullptr)
	{
		Pivot = Node->Der;
		if (Pivot->Izq != nullptr)
		{
			Node->Der = Pivot->Izq;
		}
		Pivot->Izq = Node;
		if (*Node != *Root)
		{
			CUser<T> * Parent = Root;
			while (Parent != nullptr)
			{
				if (Parent > Node)
				{
					if (Parent->Izq == Node)
					{
						Parent->Izq = Pivot;
					}
					else
					{
						Parent = Parent->Izq;
					}
				}
				else
				{
					if (Parent->Der == Node)
					{
						Parent->Der = Pivot;
					}
					else
					{
						Parent = Parent->Der;
					}
				}
			}
		}
	}
}

template class CTree<CPerson>;