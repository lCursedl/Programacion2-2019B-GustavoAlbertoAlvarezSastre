#include "CTurtle.h"

CTurtle::CTurtle()
{
	SetTag();
}

CTurtle::~CTurtle(){}

//Funcion para obtener la etiqueta de la entidad
unsigned short CTurtle::GetTag()
{
	return mTag;
}

//Funcion para asignar la etiqueta a la entidad
void CTurtle::SetTag()
{
	mTag = TURTLE;
}

//Funcion para que la entidad se reproduzca con otra
void CTurtle::Reproduce(CAnimal & Couple)
{
	//Si la entidad tiene la misma etiqueta que esta
	if (Couple.GetTag() == TURTLE)
	{
		LayEggs();
	}
}

//Funcion para que la entidad instancie nuevos animales del mismo tipo y especie
void CTurtle::LayEggs(){}