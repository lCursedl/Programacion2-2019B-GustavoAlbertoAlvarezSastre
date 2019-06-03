#include "CTurtle.h"

CTurtle::CTurtle(unsigned char Age, std::string Name, HEALTH H)
{
	cAge = Age;
	sName = Name;
	mHealth = H;
}

CTurtle::~CTurtle(){}

//Funcion para que la entidad se reproduzca con otra
void CTurtle::Reproduce(CAnimal & Couple)
{
	//Si la entidad tiene la misma etiqueta que esta
	if (typeid(Couple) == typeid(this))
	{
		LayEggs();
	}
}

//Funcion para que la entidad instancie nuevos animales del mismo tipo y especie
void CTurtle::LayEggs(){}