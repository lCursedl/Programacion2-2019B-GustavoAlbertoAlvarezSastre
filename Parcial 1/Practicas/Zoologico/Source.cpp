#include "CTurtle.h"
#include "CLion.h"
#include "CMacaw.h"
#include <vector>
#include <iostream>

using std::vector;

//enum para determinar casos de ordenamiento
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

//Funcion para ordenar una vector de animales en base a un orden dado
void QuickSort(vector<CAnimal*>&List, int First, int Last, SORT_TYPE S1, SORT_TYPE S2)
{
	//Si el tamaño del arreglo es al menos de 2
	if (First < Last)
	{
		//Se determina un pivote
		int Pivot = Last;
		//Variable para determinar el numero más pequeño
		int Smaller = First - 1;

		switch (S1)
		{
		case NAME:
			//Se recorre la lista desde el primer elemento indicado hasta el penultimo indicado
			for (int i = First; i <= Last - 1; i++)
			{
				//Se revisa si el nombre del elemento a revisar es igual al del pivote
				if (List[i]->GetName() == List[Pivot]->GetName())
				{
					//De serlo, se pasa a comparar en base a la segunda prioridad
					switch (S2)
					{
					case AGE:
						//Se revisa si la edad del elemento a revisar es igual a la del pivote
						if (List[i]->GetAge() == List[Pivot]->GetAge())
						{
							//De serlo, se compara en base a la salud
							//Si son completamente iguales ambos objetos
							if (List[i]->GetHealth() == List[Pivot]->GetHealth())
							{
								//Se omite el elemento revisado y se pasa al siguiente
								Smaller++;
							}
							//De lo contrario, se revisa si tiene mejor salud
							else if (List[i]->GetHealth() < List[Pivot]->GetHealth())
							{
								Smaller++;
								Swap(List[Smaller], List[i]);
							}
						}
						//De no serlo, se revisa si es menor su edad
						else if (List[i]->GetAge() < List[Pivot]->GetAge())
						{
							Smaller++;
							Swap(List[Smaller], List[i]);
						}
						break;
					case HEALTH:
						//Se revisa si la salud es igual en ambos casos
						if (List[i]->GetHealth() == List[Pivot]->GetHealth())
						{
							//De serlo, se compara en base a la edad
							//Si son completamente iguales ambos objetos
							if (List[i]->GetAge() == List[Pivot]->GetAge())
							{
								//Se omite el elemento revisado y se pasa al siguiente
								Smaller++;
							}
							//De lo contrario, se revisa si tiene una edad menor
							else if (List[i]->GetAge() < List[Pivot]->GetAge())
							{
								Smaller++;
								Swap(List[Smaller], List[i]);
							}
						}
						//De no serlo, se revisa si su salud es mejor
						else if (List[i]->GetHealth() < List[Pivot]->GetHealth())
						{
							Smaller++;
							Swap(List[Smaller], List[i]);
						}
						break;
					}					
				}
				//De no serlo, se determina el orden de los nombres
				else if (List[i]->GetName() < List[Pivot]->GetName())
				{
					Smaller++;
					Swap(List[Smaller], List[i]);
				}
			}
			break;
		case AGE:
			//Se recorre la lista desde el primer elemento indicado hasta el penultimo indicado
			for (int i = First; i <= Last - 1; i++)
			{
				//Se revisa si la edad de ambos elementos es igual
				if (List[i]->GetAge() == List[Pivot]->GetAge())
				{
					//De serlo, se pasa a comprobar en base a al segunda prioridad
					switch (S2)
					{
					case NAME:
						//Se comprueba si ambos elementos tienen el mismo nombre
						if (List[i]->GetName() == List[Pivot]->GetName())
						{
							//De serlo, se pasa a comprobar en base a la salud
							//Se comprueba si ambos elementos tienen la misma salud
							if (List[i]->GetHealth() == List[Pivot]->GetHealth())
							{
								//Si se cumple, se omite el elemento y se pasa al siguiente
								Smaller++;
							}
							//De no ser asi, se determina el orden
							else if (List[i]->GetHealth() < List[Pivot]->GetHealth())
							{
								Smaller++;
								Swap(List[Smaller], List[i]);
							}
						}
						//De no ser asi, se determina el orden
						else if (List[i]->GetName() < List[Pivot]->GetName())
						{
							Smaller++;
							Swap(List[Smaller], List[i]);
						}
						break;
					case HEALTH:
						//Se comprueba si ambos elementos tienen la misma salud
						if (List[i]->GetHealth() == List[Pivot]->GetHealth())
						{
							//De serlo, se pasa a comprobar en base al nombre
							//Se comprueba si ambos elementos tienen el mismo nombre
							if (List[i]->GetName() == List[Pivot]->GetName())
							{
								//Si se cumple, se omite el elemento y se pasa al siguiente
								Smaller++;
							}
							//De no ser asi, se determina el orden
							else if (List[i]->GetName() < List[Pivot]->GetName())
							{
								Smaller++;
								Swap(List[Smaller], List[i]);
							}
						}
						//De lo contrario, se determina el orden
						else if (List[i]->GetHealth() < List[Pivot]->GetHealth())
						{
							Smaller++;
							Swap(List[Smaller], List[i]);
						}
						break;
					}
					
				}
				//De no serlo, se determina cual tiene menor edad
				else if (List[i]->GetAge() < List[Pivot]->GetAge())
				{
					Smaller++;
					Swap(List[Smaller], List[i]);
				}
			}
			break;
		case HEALTH:
			//Se recorre la lista desde el primer elemento indicado hasta el penultimo indicado
			for (int i = First; i <= Last - 1; i++)
			{
				//Se revisa si la salud de ambos elementos es igual
				if (List[i]->GetHealth() == List[Pivot]->GetHealth())
				{
					//De serlo, se pasa a comprobar en base a la segunda prioridad
					switch (S2)
					{
					case NAME:
						//Se comprueba si ambos elementos tienen el mismo nombre
						if (List[i]->GetName() == List[Pivot]->GetName())
						{
							//De serlo, se pasa a revisar la edad
							//Se comprueba si ambos elementos tienen la misma edad
							if (List[i]->GetAge() == List[Pivot]->GetAge())
							{
								//Si se cumple, se omite el elemento y se pasa al siguiente
								Smaller++;
							}
							//De no ser asi, se determina el orden
							else if (List[i]->GetAge() < List[Pivot]->GetAge())
							{
								Smaller++;
								Swap(List[Smaller], List[i]);
							}
						}
						//De no ser asi, se determina el orden
						else if (List[i]->GetName() < List[Pivot]->GetName())
						{
							Smaller++;
							Swap(List[Smaller], List[i]);
						}
						break;
					case AGE:
						//Se comprueba si ambos elementos tienen la misma edad
						if (List[i]->GetAge() == List[Pivot]->GetAge())
						{
							//De serlo, se pasa a revisar el nombre
							//Se comprueba si ambos elementos tienen el mismo nombre
							if (List[i]->GetName() == List[Pivot]->GetName())
							{
								//Si se cumple, se omite el elemento y se pasa al siguiente
								Smaller++;
							}
							//De no ser asi, se determina el orden
							else if (List[i]->GetName() < List[Pivot]->GetName())
							{
								Smaller++;
								Swap(List[Smaller], List[i]);
							}
						}
						//De no ser asi, se determina el orden
						else if (List[i]->GetAge() < List[Pivot]->GetAge())
						{
							Smaller++;
							Swap(List[Smaller], List[i]);
						}
						break;
					}
					
				}
				//De no ser asi, se determina el orden
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
		QuickSort(List, First, Smaller, S1, S2);
		QuickSort(List, Smaller + 2, Last, S1, S2);
	}
}

//Funcion para comprobar que la seleccion de prioridades del usuario sea valida
unsigned short Selection(unsigned short & V1, unsigned short &  V2, unsigned short & V3)
{
	//Variable para almacenar
	unsigned short S;
	std::cout << "Introduzca un valor: ";
	std::cin >> S;
	//Se revisa si la seleccion es de un valor valido
	if (S < 0 || S > 2)
	{
		std::cout << "El valor esta fuera del rango permitido. Intente de nuevo.\n";
		return Selection(V1, V2, V3);
	}
	//Se revisa si no se repiten valores
	else if (S == V1 || S == V2 || S == V3)
	{
		std::cout << "El valor introducido ya fue registrado previamente. Intente de nuevo.\n";
		return Selection(V1, V2, V3);
	}
	return S;
}

//Operador para imprimir un puntero de tipo Animal mediante referencia
std::ostream & operator << (std::ostream & o, CAnimal * & A)
{
	return o << "Nombre: " << A->GetName() << "\tEdad: " << (unsigned short)A->GetAge() << " \tSalud: " << A->GetHealth();
}

//Funcion en la que se reciben las prioridades de ordenamiento del usuario
void Menu(unsigned short & V1, unsigned short & V2, unsigned short & V3)
{
	std::cout << "Introduzca la prioridad en la que desea que se ordenen los animales (Nombre - 0, Edad - 1, Salud - 2).\n";
	std::cout << "Prioridad 1.\n";
	V1 = Selection(V1, V2, V3);
	std::cout << "Prioridad 2.\n";
	V2 = Selection(V1, V2, V3);
	std::cout << "Prioridad 3.\n";
	V3 = Selection(V1, V2, V3);
}

int main()
{
	//Vector de punteros de tipo CAnimal
	vector<CAnimal*>MyZoo;

	//Variables en las que se almacenan las prioridades de ordenamiento del usuario
	unsigned short Order1 = 1000;
	unsigned short Order2 = 1000;
	unsigned short Order3 = 1000;

	//Objetos de diferentes tipos de animales, inicializados con valores diversos
	CTurtle TurtleA((int)1, "Joe", GOOD);
	CTurtle TurtleB((int) 25, "Mark", GOOD);
	CLion LionA((int)30, "Buck", GOOD);
	CLion LionB((int)10, "Cotor", BAD);
	CMacaw MacawA((int)2, "Pip", BAD);
	CMacaw MacawB((int)10, "Cotor", CRITICAL);

	//Insersion de los animales en el vector
	MyZoo.push_back(&TurtleA);
	MyZoo.push_back(&TurtleB);
	MyZoo.push_back(&LionA);
	MyZoo.push_back(&LionB);
	MyZoo.push_back(&MacawA);
	MyZoo.push_back(&MacawB);

	//Impresion de los animales junto con sus propiedades en pantalla
	for (int i = 0; i < MyZoo.size(); i++)
	{
		std::cout << MyZoo[i] << "\n";
	}
	std::cout << "\n";	
	//Se llama la funcion de Menu para obtener prioridades
	Menu(Order1, Order2, Order3);
	//Variable para almacenar de manera fija el tamaño del vector, sin necesidad de recalcular a futuro
	unsigned short ZooSize = MyZoo.size();
	//Se ordena el vector en base a las prioridades recibidas
	QuickSort(MyZoo, 0, ZooSize - 1, (SORT_TYPE) Order1, (SORT_TYPE)Order2);
	std::cout << "\n";
	//Se imprime de nuevo a los animales
	for (int i = 0; i < MyZoo.size(); i++)
	{
		std::cout << MyZoo[i] << "\n";
	}
	std::cout << "\n";

	/*short Input;
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
	}*/
	std::cin.ignore();
	std::cin.get();
	return 0;
}