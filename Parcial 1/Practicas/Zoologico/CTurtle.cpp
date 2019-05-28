#include "CTurtle.h"

CTurtle::CTurtle(unsigned short Age, unsigned short Hunger)
{
	mAge = Age;
	mHunger = Hunger;
	mFatigue = 0;
	mGender = 0;
}

CTurtle::CTurtle(CTurtle * T)
{
	mAge = T->mAge;
	mHunger = T->mHunger;
	mFatigue = T->mFatigue;
	mGender = T->mGender;
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

CAnimal * CTurtle::GiveCopy()
{
	return new CTurtle(this);
}