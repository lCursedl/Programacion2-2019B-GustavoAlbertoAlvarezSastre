#include "List.h"

/*------------------Single List----------------*/

void SingleList::push(SingleNode * SNode)
{
	if (*start != nullptr)
	{
		SingleNode * Temp = *start;
		SingleNode * Prev = nullptr;
		while (Temp != nullptr)
		{
			Prev = Temp;
			Temp = Temp->next;
		}
		Prev->next = SNode;
	}
	else
	{
		*start = SNode;
	}
}

void SingleList::push(SingleNode * SNode, unsigned int Pos)
{
	if (Pos <= s)
	{
		unsigned int cont = 0;
		if ((*start) != nullptr)
		{
			SingleNode * Temp = *start;
			SingleNode * Prev = nullptr;

			while (cont < Pos)
			{
				Prev = Temp;
				Temp = Temp->next;
				cont++;
			}
			if (cont == Pos)
			{
				Prev->next = SNode;
				SNode->next = Temp;
			}
		}
		else
		{
			*start = SNode;
		}
		s++;
	}
	else
	{
		std::cout << "Posicion fuera de rango.\n";
	}
}

SingleNode * SingleList::pull()
{
	if ((*start) != nullptr)
	{
		SingleNode * Temp = *start;
		SingleNode * Prev = nullptr;
		int cont = 0;
		while (cont < s - 1)
		{
			Prev = Temp;
			Temp = Temp->next;
			cont++;
		}
		Prev->next = nullptr;
		return Temp;
	}
	else
	{
		return nullptr;
	}
}

SingleNode * SingleList::pull(unsigned int Pos)
{
	if ((*start) != nullptr)
	{
		SingleNode * Temp = *start;
		SingleNode * Prev = nullptr;
		int Cont = 0;
		while (Cont < s - 1)
		{
			Prev = Temp;
			Temp = Temp->next;
			Cont++;
		}
		Prev->next = nullptr;
		return Temp;
	}
	else
	{
		return nullptr;
	}
}

void SingleList::remove()
{
	if ((*start) != nullptr)
	{
		SingleNode * Temp = *start;
		SingleNode * Prev = nullptr;
		int Cont = 0;
		while (Cont < s - 1)
		{
			Prev = Temp;
			Temp = Temp->next;
			Cont++;
		}
		Prev->next = nullptr;
		delete Temp;
		s--;
	}
	else
	{
		std::cout << "No hay valores que eliminar" << std::endl;
	}
}

void SingleList::remove(unsigned int Pos)
{
	if (*start != nullptr)
	{
		SingleNode * Temp = *start;
		SingleNode * Prev = nullptr;
		int Cont = 0;
		while (Cont < s - 1)
		{
			Prev = Temp;
			Temp = Temp->next;
			Cont++;
		}
		Prev->next = nullptr;
		delete Temp;
		s--;
	}
	else
	{
		std::cout << "No hay valores que eliminar" << std::endl;
	}
}

void SingleList::clear()
{
	if (*start != nullptr)
	{
		delete *start;
	}
}

unsigned int SingleList::size()
{
	return s;
}

SingleList::~SingleList()
{
	clear();
}

std::ostream & operator<<(std::ostream & out, const SingleList & SList)
{
	return out << **SList.start;
}

std::ostream & operator<<(std::ostream & out, const DoubleList & DList)
{
	return out << **DList.start;
}

void DoubleList::push(DoubleNode * DNode)
{
	if ((*start) != nullptr)
	{
		DoubleNode * Temp = *start;

		while (Temp->next != nullptr)
		{
			Temp->prev = Temp;
			Temp->next = Temp->next->next;
			Temp = Temp->next;

		}
		Temp->next = DNode;
		DNode->prev = Temp;
		DNode->next = nullptr;

	}
	else
	{
		*start = DNode;
	}
	s++;
}

void DoubleList::push(DoubleNode * DNode, unsigned int Pos)
{
	if (Pos < s)
	{
		if ((*start) != nullptr)
		{
			unsigned int cont = 0;
			DoubleNode * temp = *start;

			while (cont < Pos)
			{
				temp->prev = temp;
				temp->next = temp->next->next;
				temp = temp->next;
			}
			if (cont == Pos)
			{
				temp->next->prev = DNode;
				DNode->next = temp->next;
				temp->next = DNode;
				DNode->prev = temp;
			}
		}
		else
		{
			*start = DNode;
		}
		s++;
	}
	else
	{
		std::cout << "Fuera de rango.\n";
	}
}

DoubleNode * DoubleList::pull()
{
	if ((*start) != nullptr)
	{
		DoubleNode * Temp = *start;
		int Cont = 0;
		while (Cont < s - 1)
		{
			Temp = Temp->next;
			Cont++;
		}
		Temp->prev->next = nullptr;
		Temp->prev = nullptr;
		s--;
		return Temp;
	}
	else
	{
		return nullptr;
	}
}

DoubleNode * DoubleList::pull(unsigned int Pos)
{
	if (start != nullptr)
	{
		DoubleNode*Temp = *start;
		int cont = 0;
		while (cont != Pos)
		{
			Temp = Temp->next;
			cont++;
		}
		if (cont == Pos)
		{
			Temp->prev->next = Temp->next;
			Temp->next->prev = Temp->prev;
			Temp->next = nullptr;
			Temp->prev = nullptr;
			s--;
		}
		return Temp;
	}
	else
	{
		return nullptr;
	}
}

void DoubleList::remove()
{
	if ((*start) != nullptr)
	{
		DoubleNode * Temp = *start;
		while (Temp->next != nullptr)
		{
			Temp->prev = Temp;
			Temp = Temp->next;
			Temp->next = Temp->next->next;			
		}
		Temp->prev->next = nullptr;
		Temp->prev = nullptr;
		delete Temp;
		s--;
	}
	else
	{
		std::cout << "No hay valores que eliminar" << std::endl;
	}
}

void DoubleList::remove(unsigned int Pos)
{
	if (Pos < s)
	{
		if (*start != nullptr)
		{
			DoubleNode * Temp = *start;
			unsigned int Cont = 0;
			while (Cont < Pos)
			{
				Temp->prev = Temp;
				Temp = Temp->next;
				Temp->next = Temp->next->next;
			}
			Temp->prev->next = nullptr;
			Temp->prev = nullptr;
			delete Temp;
			s--;
		}
		else
		{
			std::cout << "No hay valores a eliminar ya que la lista esta vacia.\n";
		}
	}
	else
	{
		std::cout << "La posicion especificada es invalida.\n";
	}
}

void DoubleList::clear()
{
	if (*start != nullptr)
	{
		delete *start;
	}
}

unsigned int DoubleList::size()
{
	return s;
}

DoubleList::~DoubleList()
{
	clear();
}