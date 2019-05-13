#include <iostream>

int Mulby10()
{
	int num
	std::cout << "Introduzca el numero a multiplicar: ";
	std::cin >> num;
	num = (num << 3) + (num << 1);
	return num;
}

int main()
{
	int result;
	result = Mulby10();
	std::cout << result;
	std::cin.ignore();
	std::cin.get();
}