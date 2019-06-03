#pragma once
#include <typeinfo>
#include <string>

enum ANIMALS
{
	TURTLE = 0,
	LION,
	MACAW,
	FROG
};

enum HEALTH
{
	GOOD,
	BAD,
	CRITICAL
};

class CAnimal
{
protected:
	
	//Variable correspondiente a la edad del animal
	unsigned short mAge;
	//Variable correspondiente al hambre del animal
	unsigned short mHunger;
	//Variable correspondiente al cansancio del animal
	unsigned short mFatigue;
	//Variable correspondiente al genero del animal
	unsigned short mGender;

	unsigned char cAge;
	std::string sName;
	HEALTH mHealth;

public:
	~CAnimal() {};	

	//Funcion para alimentar al animal, requiere la cantidad a reducir de hambre
	virtual void Feed(unsigned short FoodAmount) = 0;
	//Funcion para reducir el nivel de cansancio del animal, requiere la cantidad a reducir
	virtual void Sleep(unsigned short RestAmount) = 0;
	/*Funcion para que el animal se reproduzca, requiere la referencia de otro animal para verificar
	si es compatible*/
	virtual void Reproduce(CAnimal &Couple) = 0;

	unsigned short GiveAge()
	{
		return mAge;
	}

	bool operator < (CAnimal &A)
	{
		return mAge < A.mAge;
	}

	bool operator == (short &s)
	{
		return mAge == s;
	}

	bool operator > (short &s)
	{
		return mAge > s;
	}

	void SetName(std::string s)
	{
		sName = s;
	}

	void SetAge(char Age)
	{
		cAge = Age;
	}

	void SetHealth(HEALTH H)
	{
		mHealth = H;
	}

	std::string GetName()
	{
		return sName;
	}

	char GetAge()
	{
		return cAge;
	}

	HEALTH GetHealth()
	{
		return mHealth;
	}
};