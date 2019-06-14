#include "CNodo.h"

CNodo::CNodo(){}

CNodo::CNodo(std::string Nombre, unsigned short Edad)
{
	mNombre = Nombre;
	mEdad = Edad;
	NextNode = nullptr;
}

CNodo::~CNodo()
{
	if (NextNode != nullptr)	
	{
		delete NextNode;
	}
}

CNodo * CNodo::GetNode()
{
	if (NextNode == nullptr)
	{
		return nullptr;
	}
	else
	{
		return NextNode;
	}
}

void CNodo::AddNode(CNodo * & Nodo)
{
	if (NextNode == nullptr)
	{
		NextNode = Nodo;
	}
	else
	{
		NextNode->AddNode(Nodo);
	}
}

void CNodo::Print()
{
	std::cout << "Nombre: " << mNombre << ", edad: " << mEdad << ".\n";
	if (NextNode != nullptr)
	{
		NextNode->Print();
	}
}