#pragma once
#include "CUser.h"
template<class T>
class CTree
{
public:
	CUser<T> * Root;

	CTree();
	CTree(CUser<T> * R);
	~CTree();

	void TreeInOrden();
	void TreePreOrden();
	void TreePostOrden();
	//Funcion para insertar un nodo en el arbol
	void Insert(CUser<T> * & Node);
	//void Delete(std::string NodeApellido);
};