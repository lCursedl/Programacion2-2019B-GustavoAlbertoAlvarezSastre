#include "CNode.h"

CNode::CNode()
{
	Next = nullptr;
	Previous = nullptr;
}

CNode::CNode(std::string Name, unsigned short Age)
{
	mName = Name;
	mAge = Age;
	Next = nullptr;
	Previous = nullptr;
}

CNode::~CNode()
{
	if (Next != nullptr)
	{
		delete Next;
	}
}

CNode * CNode::GetNext()
{
	if (Next != nullptr)
	{
		return Next;
	}
	return nullptr;
}

CNode * CNode::GetPrev()
{
	if (Previous != nullptr)
	{
		return Previous;
	}
	return nullptr;
}

void CNode::AddNext(CNode *& Node)
{
	Next = Node;
}

void CNode::AddPrev(CNode *& Node)
{
	Previous = Node;
}

void CNode::Print()
{
	std::cout << "Name: " << mName << ", age: " << mAge << ".\n";
	if (Next != nullptr && Next->mName != "" && Next->mAge != NULL)
	{
		Next->Print();
	}
}