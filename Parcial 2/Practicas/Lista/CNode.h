#pragma once
#include <string>
#include <iostream>
class CNode
{
public:
	/**/
	CNode * Next;
	CNode * Previous;
	std::string mName;
	unsigned short mAge;
	/**/
	CNode();
	CNode(std::string Name, unsigned short Age);
	~CNode();
	CNode * GetNext();
	CNode * GetPrev();
	void AddNext(CNode * & Node);
	void AddPrev(CNode * & Node);
	void Print();
};