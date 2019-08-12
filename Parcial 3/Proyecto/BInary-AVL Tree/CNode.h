#pragma once
#include <iostream>
template<class T>
class CNode
{
public:
	//Constructor/Destructor

	CNode<T>();
	~CNode<T>();

	//Data, template type
	T m_Data;

	//Left & Right child

	CNode<T>*Left;
	CNode<T>*Right;

	//Prints tree
	virtual void InOrden()=0;
	virtual void PreOrden()=0;
	virtual void PostOrden()=0;
	virtual void InsertToNode(CNode<T> * & NodetoInsert)=0;
	//Operator
	bool operator > (CNode<T> & U);
};