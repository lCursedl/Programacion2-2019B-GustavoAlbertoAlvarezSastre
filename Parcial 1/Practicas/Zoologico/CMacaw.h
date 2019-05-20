#pragma once
#include "CBird.h"
class CMacaw :
	public CBird
{
public:
	CMacaw();
	~CMacaw();

	void Reproduce(CAnimal &Couple);
	unsigned short GetTag();
	void SetTag();
	void SetNest();
};