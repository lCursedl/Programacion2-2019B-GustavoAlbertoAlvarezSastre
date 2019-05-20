#include "CLion.h"

CLion::CLion()
{
	SetTag();
}

CLion::~CLion(){}

void CLion::Reproduce(CAnimal & Couple)
{
	if (Couple.GetTag() == LION)
	{

	}
}

unsigned short CLion::GetTag()
{
	return mTag;
}

void CLion::SetTag()
{
	mTag = LION;
}

void CLion::FeedSon(CAnimal & Baby)
{
}