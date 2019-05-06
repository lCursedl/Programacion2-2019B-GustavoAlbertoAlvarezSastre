#include <iostream>
#include <string>

int Mulby10()
{
	std::string snum;
	std::cout << "Introduzca el numero a multiplicar: ";
	std::cin >> snum;
	snum += "0";
	int inum = std::stoi(snum);
	return inum;
}

int main()
{
	int result;
	result = Mulby10();
	std::cout << result;
	std::cin.ignore();
	std::cin.get();
}