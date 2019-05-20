#include "CMammal.h"

CMammal::CMammal(){}

CMammal::~CMammal(){}

void CMammal::Feed(unsigned short FoodAmount)
{
	mHunger -= FoodAmount;
}

void CMammal::Sleep(unsigned short RestAmount)
{
	mFatigue -= RestAmount;
}