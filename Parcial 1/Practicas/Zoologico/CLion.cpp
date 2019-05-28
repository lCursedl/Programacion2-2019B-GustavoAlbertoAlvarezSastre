#include "CLion.h"

CLion::CLion(unsigned short Age, unsigned short Hunger)
{
	mAge = Age;
	mHunger = Hunger;
	mFatigue = 0;
	mGender = 0;
}

CLion::CLion(CLion * L)
{
	mAge = L->mAge;
	mHunger = L->mHunger;
	mFatigue = L->mFatigue;
	mGender = L->mGender;
}

CLion::~CLion(){}

void CLion::Reproduce(CAnimal & Couple)
{
	if (typeid(Couple) == typeid(this))
	{

	}
}

void CLion::FeedSon(CAnimal & Baby)
{
}

CAnimal * CLion::GiveCopy()
{
	return new CLion(this);
}
