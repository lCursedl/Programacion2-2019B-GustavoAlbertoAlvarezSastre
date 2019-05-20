#pragma once
#include "CAnimal.h"
class CAmphibian :
	public CAnimal
{
public:
	CAmphibian();
	~CAmphibian();

	void Feed(int FoodAmount);
	void Sleep(int RestAmount);
	void Reproduce(CAnimal &Couple);

	virtual void LayEggs() = 0;
};