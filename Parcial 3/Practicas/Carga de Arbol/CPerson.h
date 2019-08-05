#pragma once
#include <string>
#include <iostream>

class CPerson
{
public:
	CPerson();
	CPerson(std::string apellido, std::string nombre, int edad);
	~CPerson();

	std::string m_apellido;
	std::string m_nombre;
	int m_edad;

	bool operator > (CPerson & Persona);
	bool operator == (CPerson & Persona);
	friend std::ostream & operator << (std::ostream & os, CPerson & P);
};