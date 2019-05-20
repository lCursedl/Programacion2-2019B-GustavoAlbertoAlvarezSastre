#pragma once
#include "CReptile.h"
class CTurtle :
	public CReptile
{
public:
	CTurtle();
	~CTurtle();

	unsigned short GetTag();
	void SetTag();
	void Reproduce(CAnimal &Couple);

	void LayEggs();
};