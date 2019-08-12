#include "CBinaryNode.h"

template <class T>
CBinaryNode<T>::CBinaryNode()
{
	this->Left = nullptr;
	this->Right = nullptr;
}

template <class T>
CBinaryNode<T>::~CBinaryNode()
{
	if (this->Left != nullptr)
	{
		delete this->Left;
	}
	if (this->Right != nullptr)
	{
		delete this->Right;
	}
}

template<class T>
void CBinaryNode<T>::InOrden()
{
	if (this->Left != nullptr)
	{
		this->Left->InOrden();
	}
	std::cout << this->m_Data << "\n";
	if (this->Right != nullptr)
	{
		this->Right->InOrden();
	}
}

template<class T>
void CBinaryNode<T>::PreOrden()
{
	std::cout << this->m_Data << "\n";
	if (this->Left != nullptr)
	{
		this->Left->PreOrden();
	}
	if (this->Right != nullptr)
	{
		this->Right->PreOrden();
	}
}

template<class T>
void CBinaryNode<T>::PostOrden()
{
	if (this->Left != nullptr)
	{
		this->Left->PostOrden();
	}
	if (this->Right != nullptr)
	{
		this->Right->PostOrden();
	}
	std::cout << this->m_Data << "\n";
}

template<class T>
void CBinaryNode<T>::InsertToNode(CNode<T>*& NodetoInsert)
{
	//Si el nodo atual es mayor al nodo a insertar
	if (*this > *NodetoInsert)
	{
		//Si el puntero derecho contiene algo
		if (this->Right != nullptr)
		{
			//Se pasa el nodo al puntero derecho para insertar
			this->Right->InsertToNode(NodetoInsert);
		}
		//De lo contrario se asigna directamente
		else
		{
			this->Right = NodetoInsert;
		}
	}
	//De lo contrario si es menor
	else
	{
		//Si el puntero izquierdo contiene algo
		if (this->Left != nullptr)
		{
			//Se pasa el nodo al puntero izquierdo para insertar
			this->Left->InsertToNode(NodetoInsert);
		}
		//De lo contrario se asigna directamente
		else
		{
			this->Left = NodetoInsert;
		}
	}
}

template class CBinaryNode <int>;
template class CNode <int>;