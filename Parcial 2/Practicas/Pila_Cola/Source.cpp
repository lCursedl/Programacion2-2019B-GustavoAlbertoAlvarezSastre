#include "CCola.h"
#include "CPila.h"

int main()
{
	unsigned short input;
	bool RunProgram = true;
	while (RunProgram)
	{
		std::cout << "Introduzca el tipo de estructura que quiere crear:\n\t1 - Pila\n\t2 - Cola\n\t3 - Salir\n";
		std::cin >> input;
		switch (input)
		{
		case 1:
		{
			CPila * MyStack = new CPila();
			bool StackCycle = true;
			while (StackCycle)
			{
				std::cin.clear();
				std::cout << "\nElija la accion a realizar: \n\t1 - Ingresar un nodo\n\t2 - Imprimir la pila\n\t3 - Sacar un elemento\n\t4 - Salir.\n";
				std::cin >> input;
				switch (input)
				{
				case 1:
				{
					std::string TempName;
					unsigned short TempAge;

					std::cout << "Introduzca un nombre: ";
					std::cin >> TempName;

					std::cout << "Introduzca una edad: ";
					std::cin >> TempAge;

					MyStack->Push(TempName, TempAge);
				}
					break;
				case 2:
					MyStack->Print();
					break;
				case 3:
					break;
				case 4:
					StackCycle = false;
					break;
				default:
					std::cout << "Opcion elegida no valida, intente de nuevo.\n";
					break;
				}
			}
			delete MyStack;
			break;
		}
		case 2:
		{
			CCola * MyQueque = new CCola();
			bool QueueCycle = true;
			while (QueueCycle)
			{
				std::cin.clear();
				std::cout << "\nElija la accion a realizar: \n\t1 - Ingresar un nodo\n\t2 - Imprimir la cola\n\t3 - Sacar un elemento\n\t4 - Salir.\n";
				std::cin >> input;
				switch (input)
				{
				case 1:
				{
					std::string TempName;
					unsigned short TempAge;

					std::cout << "Introduzca un nombre: ";
					std::cin >> TempName;

					std::cout << "Introduzca una edad: ";
					std::cin >> TempAge;

					MyQueque->Push(TempName, TempAge);
				}
				break;
				case 2:
					MyQueque->Print();
					break;
				case 3:
					break;
				case 4:
					QueueCycle = false;
					break;
				default:
					std::cout << "Opcion elegida no valida, intente de nuevo.\n";
					break;
				}
			}
			delete MyQueque;
			break;
		}
		case 3:
			RunProgram = false;
			break;
		default:
			std::cout << "Input no valido, intente de nuevo";
			break;
		}
	}	
}