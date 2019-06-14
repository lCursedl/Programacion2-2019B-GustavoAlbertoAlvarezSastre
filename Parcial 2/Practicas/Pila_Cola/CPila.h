#pragma once
#include "CNodo.h"

class CPila
{
public:
	/*Miembros*/

	CNodo * FirstNode;
	/*Metodos*/

	CPila();
	~CPila();
	void Push(std::string Name, unsigned short Age);
	CNodo * Pull();
	void Print();
	void Clear();
};