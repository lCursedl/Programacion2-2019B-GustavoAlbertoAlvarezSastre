#include "CReptile.h"

CReptile::CReptile(){}

CReptile::~CReptile(){}

void CReptile::Feed(unsigned short FoodAmount)
{
	mHunger -= FoodAmount;
}

void CReptile::Sleep(unsigned short RestAmount)
{
	mFatigue -= RestAmount;
}