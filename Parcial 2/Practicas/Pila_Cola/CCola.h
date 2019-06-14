#pragma once
#include "CNodo.h"
class CCola
{
public:
	/*Miembros*/
	CNodo * FirstNode = nullptr;
	CNodo * TempNode = nullptr;
	/*Metodos*/
	CCola();
	~CCola();
	void Push(std::string Name, unsigned short Age);
	CNodo * Pull();
	void Print();
	void Clear();
};