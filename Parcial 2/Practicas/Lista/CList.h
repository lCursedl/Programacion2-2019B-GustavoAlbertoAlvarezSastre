#pragma once
#include "CNode.h"

class CList
{
public:
	/**/
	CNode * mBegin;
	CNode * mEnd;
	/**/
	CList();
	~CList();
	void AddToBegin();
	void AddToEnd();
	void RemoveFromBegin();
	void RemoveFromEnd();
	void AddToPos(short Pos);
	void RemoveFromPos(short Pos);
	void PrintList();
};