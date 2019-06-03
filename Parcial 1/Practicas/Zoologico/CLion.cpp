#include "CLion.h"

CLion::CLion(unsigned char Age, std::string Name, HEALTH H)
{
	cAge = Age;
	sName = Name;
	mHealth = H;
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
