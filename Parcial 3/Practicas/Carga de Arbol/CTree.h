#pragma once
#include "CUser.h"
template<class T>
class CTree
{
public:
	/*Constructor/Destructor*/

	CTree();
	CTree(CUser<T> * R);
	~CTree();

	/*Miembros*/
	CUser<T> * Root;

	/*Metodos*/

	void TreeInOrden();
	void TreePreOrden();
	void TreePostOrden();
	void Insert(CUser<T> * & Node);
	void Delete(T ToDelete);
};