#pragma once
#include "CAnimal.h"
class CReptile :
	public CAnimal
{
public:
	CReptile();
	~CReptile();

	void Feed(unsigned short FoodAmount);
	void Sleep(unsigned short RestAmount);

	virtual void Reproduce(CAnimal &Couple) = 0;
	virtual unsigned short GetTag() = 0;
	virtual void SetTag() = 0;

	virtual void LayEggs() = 0;
};