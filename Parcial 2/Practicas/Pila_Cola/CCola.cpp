#include "CCola.h"

CCola::CCola()
{
	FirstNode = nullptr;
}

CCola::~CCola()
{
	if (FirstNode != nullptr)
	{
		delete FirstNode;
	}
}

void CCola::Push(std::string Name, unsigned short Age)
{
	CNodo * Node = new CNodo(Name, Age);
	if (FirstNode == nullptr)
	{
		FirstNode = Node;
	}
	else
	{
		FirstNode->AddNode(Node);
	}
}

CNodo * CCola::Pull()
{
	if (FirstNode != nullptr)
	{
		CNodo * TempNode = FirstNode;
		return TempNode;
	}
	return nullptr;
}

void CCola::Print()
{
	if (FirstNode != nullptr)
	{
		FirstNode->Print();
	}
	else
	{
		std::cout << "No elementos en la cola para imprimir.\n";
	}
}

void CCola::Clear()
{
	if (FirstNode != nullptr)
	{
		delete FirstNode;
	}
}