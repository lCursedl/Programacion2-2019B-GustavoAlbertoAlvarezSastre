#include "CMacaw.h"

CMacaw::CMacaw(unsigned short Age, unsigned short Hunger)
{
	mAge = Age;
	mHunger = Hunger;
	mFatigue = 0;
	mGender = 0;
}

CMacaw::CMacaw(CMacaw * M)
{
	mAge = M->mAge;
	mHunger = M->mHunger;
	mFatigue = M->mFatigue;
	mGender = M->mGender;
}

CMacaw::~CMacaw(){}

void CMacaw::Reproduce(CAnimal & Couple)
{
	if (typeid(Couple) == typeid(this))
	{
		SetNest();
	}
}

void CMacaw::SetNest(){}

CAnimal * CMacaw::GiveCopy()
{
	return new CMacaw(this);
}