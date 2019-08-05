#include "CPerson.h"

CPerson::CPerson()
{
	std::cout << "Introduzca un nombre: ";
	std::cin >> m_nombre;
	std::cout << "Introduzca un apellido: ";
	std::cin >> m_apellido;
	std::cout << "Introduzca una edad: ";
	std::cin >> m_edad;
}

CPerson::CPerson(std::string apellido, std::string nombre, int edad)
{
	m_apellido = apellido;
	m_nombre = nombre;
	m_edad = edad;
}

CPerson::~CPerson(){}

bool CPerson::operator>(CPerson & Persona)
{
	if (m_apellido != Persona.m_apellido)
	{
		return m_apellido > Persona.m_apellido;
	}
	else if (m_nombre != Persona.m_nombre)
	{
		return m_nombre > Persona.m_nombre;
	}
	else if (m_edad != Persona.m_edad)
	{
		return m_edad > Persona.m_edad;
	}
}

bool CPerson::operator<(CPerson & Persona)
{
	if (m_apellido != Persona.m_apellido)
	{
		return m_apellido < Persona.m_apellido;
	}
	else if (m_nombre != Persona.m_nombre)
	{
		return m_nombre < Persona.m_nombre;
	}
	else if (m_edad != Persona.m_edad)
	{
		return m_edad < Persona.m_edad;
	}
}

bool CPerson::operator==(CPerson & Persona)
{
	if (m_apellido == Persona.m_apellido && m_nombre == Persona.m_nombre && m_edad == Persona.m_edad)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream & operator<<(std::ostream & os, CPerson & P)
{
	os << "\tApellido: " << P.m_apellido << "\n\tNombre: " << P.m_nombre << "\n\tEdad: " << P.m_edad << ".\n";
	return os;
}