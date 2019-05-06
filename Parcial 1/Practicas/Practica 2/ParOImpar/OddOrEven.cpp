#include <iostream>

bool IsEven()
{
	unsigned int Num;
	std::cout << "Introduzca el numero a evaluar: ";
	std::cin >> Num;
	if (Num & 1 == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	if (IsEven())
	{
		std::cout << "El numero es impar.\n";
	}
	else
	{
		std::cout << "El numero es par.\n";
	}
	std::cin.ignore();
	std::cin.get();
}