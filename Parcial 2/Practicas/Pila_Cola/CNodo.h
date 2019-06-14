#pragma once
#include <string>
#include <iostream>
class CNodo
{
public:
	/*Miembros*/
	CNodo * NextNode;
	std::string mNombre;
	unsigned short mEdad;
	/*Metodos*/
	CNodo();
	CNodo(std::string Nombre, unsigned short Edad);
	~CNodo();
	CNodo * GetNode();
	void AddNode(CNodo * & Nodo);
	void Print();
};