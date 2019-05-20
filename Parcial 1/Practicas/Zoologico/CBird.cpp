#include "CBird.h"

CBird::CBird(){}

CBird::~CBird(){}

void CBird::Feed(unsigned short FoodAmount)
{
	mHunger -= FoodAmount;
}

void CBird::Sleep(unsigned short RestAmount)
{
	mFatigue -= RestAmount;
}