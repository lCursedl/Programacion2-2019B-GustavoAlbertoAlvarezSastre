#pragma once
#include "CNode.h"
template <class T> 
class CBinaryNode : public CNode<T>
{
public:
	//Constructors
	CBinaryNode();
	//Destructor
	~CBinaryNode();
	
	//Prints tree
	void InOrden();
	void PreOrden();
	void PostOrden();
	void InsertToNode(CNode<T> * & NodetoInsert);
};