#pragma once
#include "CUser.h"
class CTree :
	public CUser
{
public:
	CUser * Root;

	CTree();
	CTree(CUser * & R);
	CTree(std::string RootName, std::string RootLastName, int RootAge);
	~CTree();

	void TreeInOrden();
	void TreePreOrden();
	void TreePostOrden();
};