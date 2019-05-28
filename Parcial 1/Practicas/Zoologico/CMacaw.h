#pragma once
#include "CBird.h"
class CMacaw :
	public CBird
{
public:
	CMacaw(unsigned short Age, unsigned short Hunger);
	CMacaw(CMacaw * M);
	~CMacaw();

	void Reproduce(CAnimal &Couple);
	void SetNest();
	CAnimal * GiveCopy();
};