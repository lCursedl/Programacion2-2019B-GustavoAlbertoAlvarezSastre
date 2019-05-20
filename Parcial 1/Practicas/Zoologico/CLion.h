#pragma once
#include "CMammal.h"
class CLion :
	public CMammal
{
public:
	CLion();
	~CLion();

	void Reproduce(CAnimal &Couple);
	unsigned short GetTag();
	void SetTag();
	void FeedSon(CAnimal &Baby);
};