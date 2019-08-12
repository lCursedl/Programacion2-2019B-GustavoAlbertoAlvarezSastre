#include "CNode.h"
template <class T>
CNode<T>::CNode(){}

template <class T>
CNode<T>::~CNode(){}

template<class T>
bool CNode<T>::operator>(CNode<T>& U)
{
	return m_Data > U.m_Data;
}

template class CNode <int>;