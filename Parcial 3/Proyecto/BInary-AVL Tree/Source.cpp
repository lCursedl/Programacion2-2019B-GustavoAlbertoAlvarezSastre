#include "CBinaryTree.h"
#include "CAVLTree.h"
#include<iostream>
#include <Windows.h>
#include <string>

using std::cout;

void AVLMenu(int Numero)
{
	if (Numero == 1)
	{
		bool RunMenu = true;
		int input = 0;
		CAVLTree<int> * ArbolAVL = new CAVLTree<int>();
		while (RunMenu)
		{
			cout << "\nIntroduce la operacion que desees realizar:\n\t1 - Insertar nodo.\n\t2 - Eliminar nodo.\n\t3 - Impresion preorden.\n\t4 - Impresion inorden\n\t5 - Impresion postorden\n\t6 - Salir.\n";
			std::cin >> input;
			switch (input)
			{
			case 1:
				ArbolAVL->Insert();
				break;
			case 2:
				ArbolAVL->Delete();
				break;
			case 3:
				ArbolAVL->TreePreOrden();
				break;
			case 4:
				ArbolAVL->TreeInOrden();
				break;
			case 5:
				ArbolAVL->TreePostOrden();
				break;
			case 6:
				RunMenu = false;
				delete ArbolAVL;
				break;
			default:
				cout << "Opcion invalida.\n";
				std::cin.ignore();
				break;
			}
		}
	}
	
	else if (Numero == 2)
	{
		bool RunMenu = true;
		int input = 0;
		CAVLTree<char> * ArbolAVL = new CAVLTree<char>();
		while (RunMenu)
		{
			cout << "\nIntroduce la operacion que desees realizar:\n\t1 - Insertar nodo.\n\t2 - Eliminar nodo.\n\t3 - Impresion preorden.\n\t4 - Impresion inorden\n\t5 - Impresion postorden\n\t6 - Salir.\n";
			std::cin >> input;
			switch (input)
			{
			case 1:
				ArbolAVL->Insert();
				break;
			case 2:
				ArbolAVL->Delete();
				break;
			case 3:
				ArbolAVL->TreePreOrden();
				break;
			case 4:
				ArbolAVL->TreeInOrden();
				break;
			case 5:
				ArbolAVL->TreePostOrden();
				break;
			case 6:
				RunMenu = false;
				delete ArbolAVL;
				break;
			default:
				cout << "Opcion invalida.\n";
				std::cin.ignore();
				break;
			}
		}
	}
	
	
	
}

void BinaryMenu(int Numero)
{
	if (Numero == 1)
	{
		bool RunMenu = true;
		int input = 0;
		CBinaryTree<int>*ArbolAVL = new CBinaryTree<int>();
		while (RunMenu)
		{
			cout << "\nIntroduce la operacion que desees realizar:\n\t1 - Insertar nodo.\n\t2 - Eliminar nodo.\n\t3 - Impresion preorden.\n\t4 - Impresion inorden\n\t5 - Impresion postorden\n\t6 - Salir.\n";
			std::cin >> input;
			switch (input)
			{
			case 1:
				ArbolAVL->Insert();
				break;
			case 2:
				ArbolAVL->Delete();
				break;
			case 3:
				ArbolAVL->TreePreOrden();
				break;
			case 4:
				ArbolAVL->TreeInOrden();
				break;
			case 5:
				ArbolAVL->TreePostOrden();
				break;
			case 6:
				RunMenu = false;
				delete ArbolAVL;
				break;
			default:
				cout << "Opcion invalida.\n";
				std::cin.ignore();
				break;
			}
		}
	}
	else if (Numero == 2)
	{
		bool RunMenu = true;
		int input = 0;
		CBinaryTree<char>*ArbolAVL = new CBinaryTree<char>();
		while (RunMenu)
		{
			cout << "\nIntroduce la operacion que desees realizar:\n\t1 - Insertar nodo.\n\t2 - Eliminar nodo.\n\t3 - Impresion preorden.\n\t4 - Impresion inorden\n\t5 - Impresion postorden\n\t6 - Salir.\n";
			std::cin >> input;
			switch (input)
			{
			case 1:
				ArbolAVL->Insert();
				break;
			case 2:
				ArbolAVL->Delete();
				break;
			case 3:
				ArbolAVL->TreePreOrden();
				break;
			case 4:
				ArbolAVL->TreeInOrden();
				break;
			case 5:
				ArbolAVL->TreePostOrden();
				break;
			case 6:
				RunMenu = false;
				delete ArbolAVL;
				break;
			default:
				cout << "Opcion invalida.\n";
				std::cin.ignore();
				break;
			}
		}
	}
	

}

int main()
{
	bool Run = true;
	while (Run)
	{
		cout << "Bienvenido a el proyecto de arboles de Chong & Gus" << std::endl;
		int Seleccion;
		cout << "Elige una opcion:\n\t1 - Arbol AVL.\n\t2 - Arbol binario.\n\t3 - Salir." << std::endl;
		std::cin >> Seleccion;
		switch (Seleccion)
		{
		case 1:
			cout << "Que tipo de dato de arboles vas a querer?\n";
			cout << "1 para int\n";
			cout << "2 para char\n";
			std::cin >> Seleccion;
			AVLMenu(Seleccion);
			std::cin.ignore();
			break;
		case 2:
			cout << "Que tipo de dato de arboles vas a querer?\n";
			cout << "1 para int\n";
			cout << "2 para char\n";
			std::cin >> Seleccion;
			BinaryMenu(Seleccion);
			std::cin.ignore();
			break;
		case 3:
			cout << "Hasta luego.";
			std::cin.ignore();
			std::cin.get();
			Run = false;
			break;
		default:
			cout << "Esa no es una opcion valida" << std::endl;
			Sleep(3000);
			system("cls");
			std::cin.ignore();
			break;
		}
	}	
	return 0;
}