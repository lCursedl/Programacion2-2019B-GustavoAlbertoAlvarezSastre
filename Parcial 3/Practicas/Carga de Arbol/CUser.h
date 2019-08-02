#pragma once
#include <string>
#include <iostream>

class CUser
{
public:
	CUser();
	CUser(std::string apellido, std::string m_nombre, int edad);
	~CUser();

	std::string m_apellido;
	std::string m_nombre;
	int m_edad;

	CUser * Izq;
	CUser * Der;

	std::ostream & operator << (std::ostream & out);
	void InOrden();
	void PreOrden();
	void PostOrden();
	void InsertToNode(CUser * & NodetoInsert);
	bool operator > (CUser & Node);
	bool operator == (CUser & Node);
	void Delete(CUser * Node);
};