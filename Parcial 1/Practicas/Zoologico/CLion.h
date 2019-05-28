#pragma once
#include "CMammal.h"
class CLion :
	public CMammal
{
public:
	CLion(unsigned short Age, unsigned short Huger);
	CLion(CLion * L);
	~CLion();

	void Reproduce(CAnimal &Couple);
	void FeedSon(CAnimal &Baby);
	CAnimal * GiveCopy();
};