#pragma once
#include <string>
#include <iostream>

class CPerson
{
public:
	/*Metodos*/

	//Constructor predeterminado donde se inicializan los datos mediante inputs
	CPerson();
	//Constructor donde se reciben los datos directamente
	CPerson(std::string apellido, std::string nombre, int edad);
	~CPerson();

	/*Miembros*/

	std::string m_apellido;
	std::string m_nombre;
	int m_edad;

	/*Operadores*/
	bool operator > (CPerson & Persona);
	bool operator < (CPerson & Persona);
	bool operator == (CPerson & Persona);
	friend std::ostream & operator << (std::ostream & os, CPerson & P);
};