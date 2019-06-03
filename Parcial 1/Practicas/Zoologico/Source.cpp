#include "CTurtle.h"
#include "CLion.h"
#include "CMacaw.h"
#include <vector>
#include <iostream>

using std::vector;

enum SORT_TYPE
{
	NAME,
	AGE,
	HEALTH
};

//Funcion para intercambiar 2 punteros de posición
void Swap(CAnimal * & A, CAnimal * & B)
{
	CAnimal * Aptr = A;
	A = B;
	B = Aptr;
}

//Funcion para buscar por metodo binario un animal con la edad correspondiente
short BinaryShearch(vector<CAnimal*>&List, short First, short Last, short SearchNum)
{
	//Si la ultima posicion es mayor o igual a la primera,
	//Significa que estamos aun adentro de un subarreglo
	if (Last >= First)
	{
		//Se determina el punto medio del arreglo
		short Middle = (First + (Last - First) )/ 2;
		//Si este punto tiene el mismo valor que el que se busca
		if (*List[Middle] == SearchNum)
		{
			//Se entrega la posicion
			return Middle;
		}
		//De lo contrario, se revisa si el valor del punto es mayor o menor al buscado
		else if (*List[Middle] > SearchNum)
		{
			//De ser mayor, se revisa la seccion derecha del arreglo despues del punto
			return BinaryShearch(List, First, Middle - 1, SearchNum);
		}
		//De ser menor, se revisa la seccion izquierda del arreglo antes del punto
		return BinaryShearch(List, Middle + 1, Last, SearchNum);
	}
	//De lo contrario significa que no se encontro el elemento
	return -1;
}

void QuickSort(vector<CAnimal*>&List, int First, int Last, SORT_TYPE S)
{
	//Si el tamaño del arreglo es al menos de 2
	if (First < Last)
	{
		//Se determina un pivote
		int Pivot = Last;
		//Variable para determinar el numero más pequeño
		int Smaller = First - 1;
		//Se recorre la lista desde el primer elemento indicado hasta el penultimo indicado

		switch (S)
		{
		case NAME:
			for (int i = First; i <= Last - 1; i++)
			{
				if (List[i]->GetName() == List[Pivot]->GetName())
				{
					if (List[i]->GetAge() == List[Pivot]->GetAge())
					{
						if (List[i]->GetHealth() == List[Pivot]->GetHealth())
						{
							Smaller++;
						}
						else if (List[i]->GetHealth() < List[Pivot]->GetHealth())
						{
							Smaller++;
							Swap(List[Smaller], List[i]);
						}
					}
					else if (List[i]->GetAge() < List[Pivot]->GetAge())
					{
						Smaller++;
						Swap(List[Smaller], List[i]);
					}
				}
				else if (List[i]->GetName() < List[Pivot]->GetName())
				{
					Smaller++;
					Swap(List[Smaller], List[i]);
				}
			}
			break;
		case AGE:
			for (int i = First; i <= Last - 1; i++)
			{
				if (List[i]->GetAge() == List[Pivot]->GetAge())
				{
					if (List[i]->GetName() == List[Pivot]->GetName())
					{
						if (List[i]->GetHealth() == List[Pivot]->GetHealth())
						{
							Smaller++;
						}
						else if (List[i]->GetHealth() < List[Pivot]->GetHealth())
						{
							Smaller++;
							Swap(List[Smaller], List[i]);
						}
					}
					else if (List[i]->GetName() < List[Pivot]->GetName())
					{
						Smaller++;
						Swap(List[Smaller], List[i]);
					}
				}
				else if (List[i]->GetAge() < List[Pivot]->GetAge())
				{
					Smaller++;
					Swap(List[Smaller], List[i]);
				}
			}
			break;
		case HEALTH:
			for (int i = First; i <= Last - 1; i++)
			{
				if (List[i]->GetHealth() == List[Pivot]->GetHealth())
				{
					if (List[i]->GetName() == List[Pivot]->GetName())
					{
						if (List[i]->GetAge() == List[Pivot]->GetAge())
						{
							Smaller++;
						}
						else if (List[i]->GetAge() < List[Pivot]->GetAge())
						{
							Smaller++;
							Swap(List[Smaller], List[i]);
						}
					}
					else if (List[i]->GetName() < List[Pivot]->GetName())
					{
						Smaller++;
						Swap(List[Smaller], List[i]);
					}
				}
				else if (List[i]->GetHealth() < List[Pivot]->GetHealth())
				{
					Smaller++;
					Swap(List[Smaller], List[i]);
				}
			}
			break;
		}
		//Se mueve el pivote a su lugar correspondiente
		Swap(List[Smaller + 1], List[Pivot]);
		//Se llama de nuevo la funcion, diviendo en 2 la lista desde el pivote
		QuickSort(List, First, Smaller, S);
		QuickSort(List, Smaller + 2, Last, S);
	}
}

int main()
{
	vector<CAnimal*>MyZoo;

	CTurtle TurtleA((int)1, "Joe", GOOD);
	CTurtle TurtleB((int) 25, "Mark", GOOD);
	CLion LionA((int)30, "Buck", GOOD);
	CLion LionB((int)10, "Cotor", BAD);
	CMacaw MacawA((int)2, "Pip", BAD);
	CMacaw MacawB((int)10, "Cotor", CRITICAL);

	MyZoo.push_back(&TurtleA);
	MyZoo.push_back(&TurtleB);
	MyZoo.push_back(&LionA);
	MyZoo.push_back(&LionB);
	MyZoo.push_back(&MacawA);
	MyZoo.push_back(&MacawB);

	for (int i = 0; i < MyZoo.size(); i++)
	{
		std::cout << typeid(*MyZoo[i]).name() << " : " << MyZoo[i]->GetName() << ", " << (int)MyZoo[i]->GetAge() << ", " << MyZoo[i]->GetHealth() << "\n";
	}
	std::cout << "\n";

	unsigned short ZooSize = MyZoo.size();

	QuickSort(MyZoo, 0, ZooSize - 1, NAME);

	for (int i = 0; i < MyZoo.size(); i++)
	{
		std::cout << typeid(*MyZoo[i]).name() << " : " << MyZoo[i]->GetName() << ", " << (int)MyZoo[i]->GetAge() << ", " << MyZoo[i]->GetHealth() << "\n";
	}
	std::cout << "\n";

	short Input;
	std::cout << "Introduzca la edad de un animal a buscar: ";
	std::cin >> Input;
	std::cout << "Buscando animal con edad " << Input << ".\n";
	short Pos = BinaryShearch(MyZoo, 0, ZooSize, Input);
	if (Pos != -1)
	{
		std::cout << "El animal se encuentra en la posicion " << Pos << " de la lista.\n";
	}
	else
	{
		std::cout << "No existe animal con la edad especificada.\n";
	}
	std::cin.ignore();
	std::cin.get();
	return 0;
}