#pragma once
#include "CReptile.h"
class CTurtle :
	public CReptile
{
public:
	CTurtle() {};
	CTurtle(unsigned char Age, std::string Name, HEALTH H);
	~CTurtle();

	void Reproduce(CAnimal &Couple);
	void LayEggs();
};