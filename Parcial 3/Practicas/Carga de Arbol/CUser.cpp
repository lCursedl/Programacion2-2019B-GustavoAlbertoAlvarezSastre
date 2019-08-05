#include "CUser.h"
template<class T>
CUser<T>::CUser()
{
	Izq = nullptr;
	Der = nullptr;
}

template<class T>
CUser<T>::CUser(T Info) : Data(Info)
{
	Izq = nullptr;
	Der = nullptr;
}

template<class T>
CUser<T>::~CUser()
{
	if (Izq != nullptr)
	{
		delete Izq;
	}
	if (Der != nullptr)
	{
		delete Der;
	}
}

template<class T>
void CUser<T>::InOrden()
{
	if (Izq != nullptr)
	{
		Izq->InOrden();
	}
	std::cout << Data << "\n";
	if (Der != nullptr)
	{
		Der->InOrden();
	}
}

template<class T>
void CUser<T>::PreOrden()
{
	std::cout << Data << "\n";
	if (Izq != nullptr)
	{
		Izq->PreOrden();
	}
	if (Der != nullptr)
	{
		Der->PreOrden();
	}
}

template<class T>
void CUser<T>::PostOrden()
{
	if (Izq != nullptr)
	{
		Izq->PostOrden();
	}
	if (Der != nullptr)
	{
		Der->PostOrden();
	}
	std::cout << Data << "\n";
}

template<class T>
void CUser<T>::InsertToNode(CUser<T> * & NodetoInsert)
{
	//Si el nodo atual es mayor al nodo a insertar
	if (*this > *NodetoInsert)
	{
		//Si el puntero derecho contiene algo
		if (Der != nullptr)
		{
			//Se pasa el nodo al puntero derecho para insertar
			Der->InsertToNode(NodetoInsert);
		}
		//De lo contrario se asigna directamente
		else
		{
			Der = NodetoInsert;
		}
	}
	//De lo contrario si es menor
	else
	{
		//Si el puntero izquierdo contiene algo
		if (Izq != nullptr)
		{
			//Se pasa el nodo al puntero izquierdo para insertar
			Izq->InsertToNode(NodetoInsert);
		}
		//De lo contrario se asigna directamente
		else
		{
			Izq = NodetoInsert;
		}
	}
}

template<class T>
bool CUser<T>::operator>(CUser & U)
{
	return Data > U.Data;
}

template class CUser<CPerson>;