#include "CTree.h"

CTree::CTree()
{
	Root = nullptr;
}

CTree::CTree(CUser * R)
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

void CTree::Insert(CUser * & Node)
{
	//Se revisa si la raiz del arbol tiene algun elemento almacenado
	if (Root != nullptr)
	{
		//De estarlo, se pasa el nodo a la raiz para que busque donde almacenarlo
		Root->InsertToNode(Node);
	}
	else
	{
		//De lo contrario, se almacena directamente en la raiz
		Root = Node;
	}
}

void CTree::Delete(std::string NodeApellido)
{
	CUser * TempChild;
	CUser * TempFather;
	TempChild = Root;
	//Si la raiz no es un puntero nulo
	while (TempChild != nullptr)
	{
		//Se revisa si el nodo temporal tiene el valor buscado
		if (NodeApellido == TempChild->m_apellido)
		{
			if (TempChild->Izq == nullptr && TempChild->Der == nullptr)
			{
				if (TempFather != nullptr)
				{
					if (TempFather->Izq == TempChild)
					{
						TempFather->Izq = nullptr;
					}
					else if (TempFather->Der == TempChild)
					{
						TempFather->Der = nullptr;
					}
				}
				delete TempChild;
				break;
			}
			else if (TempChild->Izq == nullptr && TempChild->Der != nullptr)
			{
				if (TempFather != nullptr)
				{
					if (TempFather->Izq == TempChild)
					{
						TempFather->Izq = TempChild->Der;						
					}
					else if (TempFather->Der == TempChild)
					{
						TempFather->Der = TempChild->Der;
					}
					TempChild->Der = nullptr;
					delete TempChild;
				}
				else
				{

				}
			}
			else if (TempChild->Izq != nullptr && TempChild->Der == nullptr)
			{
				if (TempFather != nullptr)
				{
					if (TempFather->Izq == TempChild)
					{
						TempFather->Izq = TempChild->Izq;
					}
					else if (TempFather->Der == TempChild)
					{
						TempFather->Der = TempChild->Izq;
					}
					TempChild->Izq = nullptr;
					delete TempChild;
				}
				else
				{

				}
			}
			else if (TempChild->Izq != nullptr && TempChild->Der != nullptr)
			{

			}
		}
		//Se revisa si el dato recibido es de mayor valor
		else if (NodeApellido > TempChild->m_apellido)
		{
			//Si hay un valor valido hacia la derecha
			if (TempChild->Der != nullptr)
			{
				TempFather = TempChild;
				TempChild = TempChild->Der;
			}
		}
		//Se revisa en caso de ser menor
		else
		{
			//Si hay un vaor valido hacia la izquierda
			if (TempChild->Izq != nullptr)
			{
				TempFather = TempChild;
				TempChild = TempChild->Izq;
			}
		}
	}
}