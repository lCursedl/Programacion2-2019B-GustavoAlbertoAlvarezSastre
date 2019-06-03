#pragma once
#include "CBird.h"
class CMacaw :
	public CBird
{
public:
	CMacaw(unsigned char Age, std::string Name, HEALTH H);
	~CMacaw();

	void Reproduce(CAnimal &Couple);
	void SetNest();
};