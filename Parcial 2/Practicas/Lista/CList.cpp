#include "CList.h"

CList::CList()
{
	mBegin = new CNode();
	mEnd = new CNode();
	mBegin->Next = mEnd;
	mEnd->Previous = mBegin;
}

CList::~CList()
{
	if (mBegin != nullptr)
	{
		delete mBegin;
	}
}

void CList::AddToBegin()
{
	std::string TempName;
	unsigned short TempAge;
	std::cout << "Introduzca los datos para igresar el nodo.\n\tNombre: ";
	std::cin >> TempName;
	std::cout << "\tEdad: ";
	std::cin >> TempAge;
	CNode * NewNode = new CNode(TempName, TempAge);
	NewNode->AddNext(mBegin->Next);
	NewNode->AddPrev(mBegin);
	NewNode->Next->AddPrev(NewNode);
	mBegin->AddNext(NewNode);
}

void CList::AddToEnd()
{
	std::string TempName;
	unsigned short TempAge;
	std::cout << "Introduzca los datos para igresar el nodo.\n\tNombre: ";
	std::cin >> TempName;
	std::cout << "\tEdad: ";
	std::cin >> TempAge;
	CNode * NewNode = new CNode(TempName, TempAge);
	NewNode->AddNext(mEnd);
	NewNode->AddPrev(mEnd->Previous);
	NewNode->Previous->AddNext(NewNode);
	mEnd->AddPrev(NewNode);
}

void CList::RemoveFromBegin()
{
	if (mBegin->Next != mEnd)
	{
		CNode * Temp = mBegin->Next;
		mBegin->Next = mBegin->Next->Next;
		mBegin->Next->Previous = mBegin;
		Temp->Next = nullptr;
		Temp->Previous = nullptr;
		delete Temp;
	}
	else
	{
		std::cout << "Imposible remover elementos de lista vacia.\n";
	}
}

void CList::RemoveFromEnd()
{
	if (mEnd->Previous != mBegin)
	{
		CNode * Temp = mEnd->Previous;
		mEnd->Previous = mEnd->Previous->Previous;
		mEnd->Previous->Next = mEnd;
		Temp->Next = nullptr;
		Temp->Previous = nullptr;
		delete Temp;
	}
	else
	{
		std::cout << "Imposible remover elementos de lista vacia.\n";
	}
}

void CList::AddToPos(short Pos)
{
	if (Pos < 1)
	{
		std::cout << "Posicion ingresada no valida.\n";
	}
	else if (Pos == 1)
	{
		AddToBegin();
	}
	else if (mBegin->Next != mEnd)
	{
		CNode * Temp = mBegin;
		short NodePos = 0;
		while (Temp != mEnd)
		{
			if (NodePos == Pos)
			{
				std::string TempName;
				unsigned short TempAge;
				std::cout << "Introduzca los datos para igresar el nodo.\n\tNombre: ";
				std::cin >> TempName;
				std::cout << "\tEdad: ";
				std::cin >> TempAge;
				CNode * NewNode = new CNode(TempName, TempAge);
				NewNode->Next = Temp;
				NewNode->Previous = Temp->Previous;
				Temp->Previous = NewNode;
				NewNode->Previous->Next = NewNode;
				break;
			}
			else
			{
				Temp = Temp->Next;
				NodePos++;
			}			
		}
		if (NodePos+1 == Pos)
		{
			AddToEnd();
		}
		else
		{
			std::cout << "La posicion especificada no se encuentra.\n";
		}
	}
	else
	{
		std::cout << "No se puede agregar un elemento en esa posicion ya que la lista esta vacia.\n";
	}
}

void CList::RemoveFromPos(short Pos)
{
	if (Pos < 1)
	{
		std::cout << "Posicion ingresada no valida.\n";
	}
	else if (mBegin->Next != mEnd)
	{
		CNode * Temp = mBegin->Next;
		short NodePos = 1;
		while (Temp != mEnd)
		{
			if (NodePos == Pos)
			{
				Temp->Next->Previous = Temp->Previous;
				Temp->Previous->Next = Temp->Next;
				Temp->Next = nullptr;
				Temp->Previous = nullptr;
				delete Temp;
				break;
			}
			else
			{
				Temp = Temp->Next;
				NodePos++;
			}
		}
		if (NodePos < Pos)
		{
			std::cout << "La posicion especificada no se encuentra.\n";
		}
	}
}

void CList::PrintList()
{
	if (mBegin->Next != mEnd)
	{
		mBegin->Next->Print();
	}
}