#pragma once
#include "CMammal.h"
class CLion :
	public CMammal
{
public:
	CLion(unsigned char Age, std::string Name, HEALTH H);
	~CLion();

	void Reproduce(CAnimal &Couple);
	void FeedSon(CAnimal &Baby);
};