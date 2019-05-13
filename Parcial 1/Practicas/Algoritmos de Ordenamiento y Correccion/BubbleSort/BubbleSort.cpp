#include <vector>
#include <iostream>

using std::vector;

vector<int>BubbleSort(vector<int>List)
{
	//Variable para almacenar el tamaño de la lista
	int ListSize = List.size();
	//Variable para retornar la lista ordenada
	vector<int>SortedList = List;
	//Ciclo para determinar el límite a revisar
	for (int i = 0; i < ListSize - 1; i++)
	{
		//Ciclo para verificar los numeros adyacentes
		for (int j = 0; j < ListSize-i-1; j++)
		{
			//Si numero actual es mayor al siguiente
			if (SortedList[j] > SortedList[j + 1])
			{
				//Se realiza el cambio de valores
				int Temp = SortedList[j];
				SortedList[j] = SortedList[j + 1];
				SortedList[j + 1] = Temp;
			}
		}
	}
	//Al terminar se retorna una nueva lista ordenada
	return SortedList;
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
	vector<int>NewList = BubbleSort(UserList);
	return 0;
}