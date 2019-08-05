#pragma once
#include "CPerson.h"

template <class T>
class CUser
{
public:
	CUser();
	CUser(T Info);
	~CUser();

	T Data;

	CUser<T> * Izq;
	CUser<T> * Der;
	
	void InOrden();
	void PreOrden();
	void PostOrden();
	void InsertToNode(CUser<T> * & NodetoInsert);
	bool operator > (CUser<T> & U);
};