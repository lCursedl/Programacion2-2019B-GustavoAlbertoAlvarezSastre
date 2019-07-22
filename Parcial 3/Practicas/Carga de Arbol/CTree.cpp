#include "CTree.h"

CTree::CTree()
{
	Root = nullptr;
}

CTree::CTree(CUser * & R)
{
	Root = R;
}

CTree::CTree(std::string RootName, std::string RootLastName, int RootAge)
{
	Root = new CUser(RootName, RootLastName, RootAge);
}

CTree::~CTree()
{
	if (Root != nullptr)
	{
		delete Root;
	}
}

void CTree::TreeInOrden()
{
	if (Root != nullptr)
	{
		Root->InOrden();
	}
}

void CTree::TreePreOrden()
{
	if (Root != nullptr)
	{
		Root->PreOrden();
	}
}

void CTree::TreePostOrden()
{
	if (Root != nullptr)
	{
		Root->PostOrden();
	}
}