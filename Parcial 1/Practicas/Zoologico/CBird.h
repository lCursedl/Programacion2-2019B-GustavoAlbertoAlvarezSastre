#pragma once
#include "CAnimal.h"
class CBird :
	public CAnimal
{
public:
	CBird();
	~CBird();
	virtual void Reproduce(CAnimal &Couple) = 0;
	virtual void SetNest() = 0;

	void Feed(unsigned short FoodAmount);
	void Sleep(unsigned short RestAmount);
	virtual CAnimal* GiveCopy() = 0;
};