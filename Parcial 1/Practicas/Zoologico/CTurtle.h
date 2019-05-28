#pragma once
#include "CReptile.h"
class CTurtle :
	public CReptile
{
public:
	CTurtle() {};
	CTurtle(unsigned short Age, unsigned short Hunger);
	CTurtle(CTurtle* T);
	~CTurtle();

	void Reproduce(CAnimal &Couple);
	void LayEggs();
	CAnimal* GiveCopy();
};