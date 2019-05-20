#include "CMacaw.h"

CMacaw::CMacaw()
{
	SetTag();
}


CMacaw::~CMacaw(){}

void CMacaw::Reproduce(CAnimal & Couple)
{
	if (Couple.mTag == MACAW)
	{
		SetNest();
	}
}

unsigned short CMacaw::GetTag()
{
	return mTag;
}

void CMacaw::SetTag()
{
	mTag = MACAW;
}

void CMacaw::SetNest()
{
}