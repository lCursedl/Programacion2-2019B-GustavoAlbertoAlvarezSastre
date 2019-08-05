#pragma once
#include "CPerson.h"

template <class T>
class CUser
{
public:
	//Constructores/Destructores

	CUser();
	CUser(T Info);
	~CUser();

	//Dato del tipo del template
	T Data;

	//Punteros de hijo izquierdo/derecho

	CUser<T> * Izq;
	CUser<T> * Der;
	/*Metodos*/

	void InOrden();
	void PreOrden();
	void PostOrden();
	void InsertToNode(CUser<T> * & NodetoInsert);

	/*Operadores*/

	bool operator > (CUser<T> & U);
};