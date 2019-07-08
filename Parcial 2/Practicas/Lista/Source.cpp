#include "CList.h"

int main()
{
	short input;
	bool RunProgram = true;
	CList * MyList = new CList();
	while (RunProgram)
	{
		std::cout << "\nIntroduzca la operacion que desea realizar:\n\t1 - Insertar nodo al inicio.\n\t2 - Insertar nodo al final.\n\t3 - Insertar nodo en X posicion.\n\t4 - Eliminar nodo al inicio\n\t5 - Eliminar nodo al final.\n\t6 - Eliminar nodo en X posicion.\n\t7 - Imprimir lista.\n\t8 - Salir.\n";
		std::cin >> input;
		switch (input)
		{
		case 1:
			std::cin.clear();
			MyList->AddToBegin();
			break;
		case 2:
			std::cin.clear();
			MyList->AddToEnd();
			break;
		case 3:
			std::cin.clear();
			std::cout << "Introduzca la posicion en la que desea realizar la accion: ";
			std::cin >> input;
			MyList->AddToPos(input);
			break;
		case 4:
			std::cin.clear();
			MyList->RemoveFromBegin();
			break;
		case 5:
			std::cin.clear();
			MyList->RemoveFromEnd();
			break;
		case 6:
			std::cin.clear();
			std::cout << "Introduzca la posicion en la que desea realizar la accion: ";
			std::cin >> input;
			MyList->RemoveFromPos(input);
			break;
		case 7:
			std::cin.clear();
			MyList->PrintList();
			std::cout << "\n";
			break;
		case 8:
			RunProgram = false;
			break;
		default:
			std::cout << "Opcion elegida no valida, intente de nuevo.\n";
			std::cin.clear();
			break;
		}
	}
	delete MyList;
	return 0;
}