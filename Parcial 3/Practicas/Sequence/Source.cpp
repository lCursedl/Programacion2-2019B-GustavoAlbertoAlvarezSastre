#include <iostream>

int Sequence(int Init, int Limit, int Steps)
{
	//Se obtiene la cantidad de veces que se va a sumar el numero sin contar el primer dato
	int Iterator = (Limit - Init) / Steps;
	//Se obtiene el resultado en base al iterador
	int Result = (Steps * ((Iterator * (Iterator + 1)) / 2)) + (Init * (Iterator + 1));
	return Result;
}

int main()
{
	int UserInit;
	int UserLimit;
	int UserSteps;
	std::cout << "Introduzca el numero del cual empezar: ";
	std::cin >> UserInit;
	std::cout << "Introduzca el numero en el cual dejar de sumar: ";
	std::cin >> UserLimit;
	std::cout << "Introduzca el numero por el que se incrementa cada paso: ";
	std::cin >> UserSteps;
	std::cout << "El resultado es " << Sequence(UserInit, UserLimit, UserSteps) << ".\n";
	std::cin.ignore();
	std::cin.get();
	return 0;
}