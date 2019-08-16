#include "CAVLNode.h"


template <class T>
CAVLNode<T>::CAVLNode()
{
	std::cout << "Introduce el valor del nodo:\n";
	std::cin >> m_Data;
	Left = nullptr;
	Right = nullptr;
}

template<class T>
CAVLNode<T>::CAVLNode(T Info) : m_Data(Info)
{
	Left = nullptr;
	Right = nullptr;
}

template <class T>
CAVLNode<T>::~CAVLNode()
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
void CAVLNode<T>::InOrden()
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
void CAVLNode<T>::PreOrden()
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
void CAVLNode<T>::PostOrden()
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
void CAVLNode<T>::InsertToNode(CAVLNode<T>*& NodetoInsert)
{
	if (*this < *NodetoInsert)
	{
		//Si el puntero derecho contiene algo
		if (Right != nullptr)
		{
			//Se pasa el nodo al puntero derecho para insertar
			Right->InsertToNode(NodetoInsert);
			Right = Right->Balance();
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
			Left = Left->Balance();
		}
		//De lo contrario se asigna directamente
		else
		{
			Left = NodetoInsert;
		}
	}
}

template<class T>
void CAVLNode<T>::DeleteNode(T ToDelete)
{
}

template<class T>
int CAVLNode<T>::GetLevel()
{
	int LeftLevel = 0;
	int RightLevel = 0;
	if (Left != nullptr)
	{
		LeftLevel = this->Left->GetLevel();
	}
	if (Right != nullptr)
	{
		RightLevel = Right->GetLevel();
	}
	if (LeftLevel > RightLevel)
	{
		return 1 + LeftLevel;
	}
	else if (RightLevel > LeftLevel)
	{
		return 1 + RightLevel;
	}
	else
	{
		return 1;
	}
}

template<class T>
CAVLNode<T>* CAVLNode<T>::L_Rotate()
{
	if (this->Right != nullptr)
	{
		CAVLNode<T> * Pivot = this->Right;
		if (Pivot->Left != nullptr)
		{
			this->Right = Pivot->Left;
		}
		else
		{
			this->Right = nullptr;
		}
		Pivot->Left = this;
		return Pivot;
	}	
	return this;
}

template<class T>
CAVLNode<T>* CAVLNode<T>::R_Rotate()
{
	if (this->Left != nullptr)
	{
		CAVLNode<T> * Pivot = this->Left;
		if (Pivot->Right != nullptr)
		{
			this->Left = Pivot->Right;
		}
		else
		{
			this->Left = nullptr;
		}
		Pivot->Right = this;
		return Pivot;
	}
	return this;
}

template<class T>
CAVLNode<T>* CAVLNode<T>::Balance()
{
	int LeftBalance = 0;
	int RightBalance = 0;
	if (Left != nullptr)
	{
		LeftBalance = Left->GetLevel();
	}
	if (Right != nullptr)
	{
		RightBalance = Right->GetLevel();
	}
	if (LeftBalance < RightBalance)
	{
		if ((RightBalance - LeftBalance) > 1)
		{
			return L_Rotate();
		}
		else
		{
			return this;
		}
	}
	else if (LeftBalance > RightBalance)
	{
		if ((LeftBalance - RightBalance) > 1)
		{
			return R_Rotate();
		}
		else
		{
			return this;
		}
	}
	else
	{
		return this;
	}
}

template<class T>
bool CAVLNode<T>::operator>(CAVLNode<T>& N)
{
	return m_Data > N.m_Data;
}

template<class T>
bool CAVLNode<T>::operator<(CAVLNode<T>& N)
{
	return m_Data < N.m_Data;
}

template<class T>
bool CAVLNode<T>::operator==(CAVLNode<T>& N)
{
	return m_Data == N.m_Data;
}

template class CAVLNode<int>;
template class CAVLNode<char>;