#include "CPila.h"

CPila::CPila()
{
	FirstNode = nullptr;
}

CPila::~CPila()
{
	if (FirstNode != nullptr)
	{
		delete FirstNode;
	}
}

void CPila::Push(std::string Name, unsigned short Age)
{
	CNodo * Node = new CNodo(Name, Age);
	if (FirstNode != nullptr)
	{
		CNodo * Temp = FirstNode;
		FirstNode = Node;
		Node->AddNode(Temp);
	}
	else
	{
		FirstNode = Node;
	}
}

CNodo * CPila::Pull()
{
	return nullptr;
}

void CPila::Print()
{
	if (FirstNode != nullptr)
	{
		FirstNode->Print();
	}
	else
	{
		std::cout << "No elementos en la pila para imprimir.\n";
	}
}

void CPila::Clear()
{
	if (FirstNode != nullptr)
	{
		delete FirstNode;
	}
}