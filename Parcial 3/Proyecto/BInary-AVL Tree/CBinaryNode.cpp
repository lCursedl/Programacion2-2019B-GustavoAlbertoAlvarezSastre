#include "CBinaryNode.h"

template <class T>
CBinaryNode<T>::CBinaryNode()
{
	std::cout << "Introduce el valor del nodo:\n";
	std::cin >> m_Data;
	Left = nullptr;
	Right = nullptr;
}

template <class T>
CBinaryNode<T>::~CBinaryNode()
{
	if (Left != nullptr)
	{
		delete Left;
	}
	if (Right != nullptr)
	{
		delete Right;
	}
}

template<class T>
void CBinaryNode<T>::InOrden()
{
	if (Left != nullptr)
	{
		Left->InOrden();
	}
	std::cout << m_Data << "\n";
	if (Right != nullptr)
	{
		Right->InOrden();
	}
}

template<class T>
void CBinaryNode<T>::PreOrden()
{
	std::cout << m_Data << "\n";
	if (Left != nullptr)
	{
		Left->PreOrden();
	}
	if (Right != nullptr)
	{
		Right->PreOrden();
	}
}

template<class T>
void CBinaryNode<T>::PostOrden()
{
	if (Left != nullptr)
	{
		Left->PostOrden();
	}
	if (Right != nullptr)
	{
		Right->PostOrden();
	}
	std::cout << m_Data << "\n";
}

template<class T>
void CBinaryNode<T>::InsertToNode(CBinaryNode<T>*& NodetoInsert)
{
	//Si el nodo atual es mayor al nodo a insertar
	if (*this > *NodetoInsert)
	{
		//Si el puntero derecho contiene algo
		if (Right != nullptr)
		{
			//Se pasa el nodo al puntero derecho para insertar
			Right->InsertToNode(NodetoInsert);
		}
		//De lo contrario se asigna directamente
		else
		{
			Right = NodetoInsert;
		}
	}
	//De lo contrario si es menor
	else
	{
		//Si el puntero izquierdo contiene algo
		if (Left != nullptr)
		{
			//Se pasa el nodo al puntero izquierdo para insertar
			Left->InsertToNode(NodetoInsert);
		}
		//De lo contrario se asigna directamente
		else
		{
			Left = NodetoInsert;
		}
	}
}

template<class T>
bool CBinaryNode<T>::operator>(CBinaryNode<T>& N)
{
	return m_Data > N.m_Data;
}

template<class T>
bool CBinaryNode<T>::operator==(CBinaryNode<T>& N)
{
	return m_Data == N.m_Data;
}

template<class T>
bool CBinaryNode<T>::operator<(CBinaryNode<T>& N)
{
	return m_Data < N.m_Data;
}



template class CBinaryNode <int>;
template class CBinaryNode<char>;

