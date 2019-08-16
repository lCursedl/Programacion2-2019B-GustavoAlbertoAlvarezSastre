#pragma once
#include <iostream>

template <class T>
class CAVLNode
{
public:
	CAVLNode();
	CAVLNode(T Info);
	~CAVLNode();
	
	CAVLNode<T> * Left;
	CAVLNode<T> * Right;

	T m_Data;

	void InOrden();
	void PreOrden();
	void PostOrden();

	void InsertToNode(CAVLNode<T> * & NodetoInsert);
	void DeleteNode(T ToDelete);
	int GetLevel();
	CAVLNode<T> * L_Rotate();
	CAVLNode<T> * R_Rotate();
	CAVLNode<T> * Balance();

	bool operator > (CAVLNode<T> & N);
	bool operator < (CAVLNode<T> & N);
	bool operator == (CAVLNode<T> & N);

};