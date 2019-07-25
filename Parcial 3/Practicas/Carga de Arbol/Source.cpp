#include "CTree.h"

int main()
{
	bool Cycle = true;
	int input;
	CTree * MyTree = new CTree();
	CUser * TestNode = new CUser("Gustavo", "Alvarez", 4);	
	MyTree->Insert(TestNode);
	TestNode = new CUser("Ramses", "Guerrero", 2);
	MyTree->Insert(TestNode);
	TestNode = new CUser("Victor", "Cota", 3);
	MyTree->Insert(TestNode);
	TestNode = new CUser("Jesus", "Del Moral", 1);
	MyTree->Insert(TestNode);
	TestNode = new CUser("Sebastian", "Magno", 5);
	MyTree->Insert(TestNode);
	TestNode = new CUser("Juan", "Chong", 6);
	MyTree->Insert(TestNode);
	TestNode = new CUser("Roberto", "Ramirez", 7);
	MyTree->Insert(TestNode);
	TestNode = new CUser("Emilio", "Solis", 8);
	MyTree->Insert(TestNode);
	TestNode = new CUser("John", "Smith", 9);
	MyTree->Insert(TestNode);

	while (Cycle)
	{
		std::cout << "Elija en que orden quiere imprimir el arbol: \n\t1 - Pre-orden\n\t2 - In-orden\n\t3 - Post-orden\n\t4 - Salir\n";
		std::cin >> input;
		switch (input)
		{
		case 1:
			std::cout << "Pre-orden:\n";
			MyTree->TreePreOrden();
			std::cin.ignore();
			break;
		case 2:
			std::cout << "In-orden:\n";
			MyTree->TreeInOrden();
			std::cin.ignore();
			break;
		case 3:
			std::cout << "Post-orden:\n";
			MyTree->TreePostOrden();
			std::cin.ignore();
			break;
		case 4:
			Cycle = false;
			delete MyTree;
			break;
		default:
			std::cout << "Opcion invalida.\n";
			std::cin.ignore();
			break;
		}
	}
	return 0;
}