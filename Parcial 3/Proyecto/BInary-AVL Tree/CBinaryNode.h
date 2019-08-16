#pragma once
#include <iostream>

template <class T> 
class CBinaryNode
{
public:
	//Constructors
	CBinaryNode();
	//Destructor
	~CBinaryNode();
	
	//Data, template type
	T m_Data;

	//Left & Right child

	CBinaryNode<T>*Left;
	CBinaryNode<T>*Right;

	//Prints tree
	void InOrden();
	void PreOrden();
	void PostOrden();

	//Prints tree
	void InsertToNode(CBinaryNode<T> * & NodetoInsert);

	bool operator > (CBinaryNode<T> & N);
	bool operator == (CBinaryNode<T> & N);
	bool operator < (CBinaryNode<T> & N);

	
};
