#include "CUser.h"

CUser::CUser()
{
	Izq = nullptr;
	Der = nullptr;
}

CUser::CUser(std::string apellido, std::string nombre, int edad)
{
	m_apellido = apellido;
	m_nombre = nombre;
	m_edad = edad;
}

CUser::~CUser()
{
	if (Izq != nullptr)
	{
		delete Izq;
	}
	if (Der != nullptr)
	{
		delete Der;
	}
}

std::ostream & CUser::operator<<(std::ostream & out)
{
	out << "Nombre: " << m_nombre << ".\n\tApellido: " << m_apellido << ".\n\t\tEdad: " << m_edad << ".\n";
	return out;
}

void CUser::InOrden()
{
	if (Izq != nullptr)
	{
		Izq->InOrden();
	}
	std::cout << "\t" << m_apellido << "\n";
	std::cout << "\t" << m_nombre << "\n";
	std::cout << "\t" << m_edad << "\n";
	std::cout << "\n";
	if (Der != nullptr)
	{
		Der->InOrden();
	}
}

void CUser::PreOrden()
{
	std::cout << "\t" << m_apellido << "\n";
	std::cout << "\t" << m_nombre << "\n";
	std::cout << "\t" << m_edad << "\n";
	std::cout << "\n";
	if (Izq != nullptr)
	{
		Izq->PreOrden();
	}
	if (Der != nullptr)
	{
		Der->PreOrden();
	}
}

void CUser::PostOrden()
{
	if (Izq != nullptr)
	{
		Izq->PostOrden();
	}
	if (Der != nullptr)
	{
		Der->PostOrden();
	}
	std::cout << "\t" << m_apellido << "\n";
	std::cout << "\t" << m_nombre << "\n";
	std::cout << "\t" << m_edad << "\n";
	std::cout << "\n";
}