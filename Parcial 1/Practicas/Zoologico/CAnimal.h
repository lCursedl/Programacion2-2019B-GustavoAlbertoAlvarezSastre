#pragma once

enum ANIMALS
{
	TURTLE = 0,
	LION,
	MACAW,
	FROG
};

class CAnimal
{
public:
	CAnimal() {};
	~CAnimal() {};

	//Variable correspondiente a la edad del animal
	unsigned short mAge;
	//Variable correspondiente al hambre del animal
	unsigned short mHunger;
	//Variable correspondiente al cansancio del animal
	unsigned short mFatigue;
	//Variable correspondiente a la etiqueta del animal
	unsigned short mTag;
	//Variable correspondiente al genero del animal
	unsigned short mGender;

	//Funcion para alimentar al animal, requiere la cantidad a reducir de hambre
	virtual void Feed(unsigned short FoodAmount) = 0;
	//Funcion para reducir el nivel de cansancio del animal, requiere la cantidad a reducir
	virtual void Sleep(unsigned short RestAmount) = 0;
	/*Funcion para que el animal se reproduzca, requiere la referencia de otro animal para verificar
	si es compatible*/
	virtual void Reproduce(CAnimal &Couple) = 0;
	virtual unsigned short GetTag() = 0;
	virtual void SetTag() = 0;
};