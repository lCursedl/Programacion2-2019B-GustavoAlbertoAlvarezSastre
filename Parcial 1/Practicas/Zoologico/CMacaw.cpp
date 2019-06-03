#include "CMacaw.h"

CMacaw::CMacaw(unsigned char Age, std::string Name, HEALTH H)
{
	cAge = Age;
	sName = Name;
	mHealth = H;
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