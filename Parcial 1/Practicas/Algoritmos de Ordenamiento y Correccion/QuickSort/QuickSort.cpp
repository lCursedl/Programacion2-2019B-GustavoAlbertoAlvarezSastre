#include <vector>
#include <iostream>

using std::vector;

//Funcion para intercambiar valores recibidos
void Swap(int &A, int &B)
{
	int Temp = A;
	A = B;
	B = Temp;
}

void QuickSort(vector<int>&List, int First, int Last)
{
	//Si el tamaño del arreglo es al menos de 2
	if (First < Last)
	{
		//Se determina un pivote
		int Pivot = Last;
		//Variable para determinar el numero más pequeño
		int Smaller = First - 1;
		//Se recorre la lista desde el primer elemento indicado hasta el penultimo indicado
		for (int i = First; i <= Last - 1; i++)
		{
			//Se revisa si el numero actual es menor al pivote
			if (List[i] < List[Pivot])
			{
				Smaller++;
				Swap(List[Smaller], List[i]);
			}
		}
		//Se mueve el pivote a su lugar correspondiente
		Swap(List[Smaller + 1], List[Pivot]);
		//Se llama de nuevo la funcion, diviendo en 2 la lista desde el pivote
		QuickSort(List, First, Smaller);
		QuickSort(List, Smaller + 2, Last);
	}
}

int main()
{
	//Variable para almacenar los numeros que introduzca el usuario
	vector<int>UserList;
	//Variables para el numero de elementos a registrar, así como un temporal
	int UserLsize, Num;
	std::cout << "Introduzca la cantidad de numeros a incluir en la lista: ";
	std::cin >> UserLsize;
	for (int i = 0; i < UserLsize; i++)
	{
		std::cout << "Elemento " << i << ": ";
		std::cin >> Num;
		UserList.push_back(Num);
	}
	QuickSort(UserList, 0, UserLsize - 1);
	return 0;
}