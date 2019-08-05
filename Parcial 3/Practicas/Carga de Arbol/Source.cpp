#include "CTree.h"

int main()
{
	bool Cycle = true;
	int input;
	CTree <CPerson> * MyTree = new CTree<CPerson>();
	CUser<CPerson> * TestNode = new CUser<CPerson>(CPerson("Alvarez", "Gustavo", 4));
	MyTree->Insert(TestNode);
	TestNode = new CUser<CPerson>(CPerson("Guerrero", "Ramses", 2));
	MyTree->Insert(TestNode);
	TestNode = new CUser<CPerson>(CPerson("Cota", "Victor", 3));
	MyTree->Insert(TestNode);
	TestNode = new CUser<CPerson>(CPerson("Del Moral", "Jesus", 1));
	MyTree->Insert(TestNode);
	TestNode = new CUser<CPerson>(CPerson("Magno", "Sebastian", 5));
	MyTree->Insert(TestNode);
	TestNode = new CUser<CPerson>(CPerson("Chong", "Juan", 6));
	MyTree->Insert(TestNode);
	TestNode = new CUser<CPerson>(CPerson("Ramirez", "Roberto", 7));
	MyTree->Insert(TestNode);
	TestNode = new CUser<CPerson>(CPerson("Solis", "Emilio", 8));
	MyTree->Insert(TestNode);
	TestNode = new CUser<CPerson>(CPerson("Smith", "Jonh", 9));
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
	std::cin.get();
	return 0;
}