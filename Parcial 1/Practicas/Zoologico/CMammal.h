#pragma once
#include "CAnimal.h"
class CMammal :
	public CAnimal
{
public:
	CMammal();
	~CMammal();

	void Feed(unsigned short FoodAmount);
	void Sleep(unsigned short RestAmount);

	virtual void Reproduce(CAnimal &Couple) = 0;
	virtual unsigned short GetTag() = 0;
	virtual void SetTag() = 0;
	virtual void FeedSon(CAnimal &Baby) = 0;
};