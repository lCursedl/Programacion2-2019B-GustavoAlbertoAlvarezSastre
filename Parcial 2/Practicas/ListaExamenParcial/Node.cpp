#include "Node.h"

/*--------Node--------*/
const std::string Node::getName()
{
	return name;
}

void Node::setName(std::string NameString)
{
	name = NameString;
}

const std::string Node::getLastName()
{
	return lastName;
}

void Node::setLastName(std::string LNameString)
{
	lastName = LNameString;
}

const std::string Node::getEmail()
{
	return email;
}

void Node::setEmail(std::string EmailString)
{
	email = EmailString;
}

void Node::setBirthDate(unsigned char cday, unsigned char cmonth, unsigned char cyear)
{
	birthDay = cday;
	birthMonth = cmonth;
	birthYear = cyear;
}

const std::string Node::getFullName()
{
	return name + lastName;
}

const unsigned int Node::getAge()
{
	return birthDay;
}

/*------Single Node--------*/

bool SingleNode::operator > (SingleNode & SNode)
{
	return this->getAge() > SNode.getAge();
}

bool SingleNode::operator<(SingleNode & SNode)
{
	return getAge() < SNode.getAge();
}

SingleNode::~SingleNode()
{
	if (next != nullptr)
	{
		delete next;
	}
}

std::ostream & operator<<(std::ostream & out, SingleNode & SNode)
{
	out << "\n\nThe name is:" << SNode.getFullName() << "\nThe age is: " << SNode.getAge() << "\nThe email is: " << SNode.getEmail();
	if (SNode.next == nullptr)
	{
		return out;
	}
	else
	{
		return out << SNode.next;
	}
}

std::istream & operator>>(std::istream & in, SingleNode & SNode)
{
	std::cout << "Ingrese un nombre: ";
	in >> SNode.name;
	std::cout << "Ingrese un apellido: ";
	in >> SNode.lastName;
	std::cout << "Ingrese un email: ";
	in >> SNode.email;
	std::cout << "Ingrese un dia de nacimiento: ";
	in >> SNode.birthDay;
	std::cout << "Ingrese un mes de nacimiento: ";
	in >> SNode.birthMonth;
	std::cout << "Ingrese un año de nacimiento: ";
	in >> SNode.birthYear;
	return in;
}

/*------------------------------Double Node---------------------------------------------------------------------------------------------------*/

std::ostream & operator<<(std::ostream & out, DoubleNode & SNode)
{
	out << "\n\nThe name is:" << SNode.getFullName() << "\nThe age is: " << SNode.getAge() << "\nThe email is: " << SNode.getEmail();
	if (SNode.next == nullptr)
	{
		return out;
	}
	else
	{
		return out << SNode.next;
	}
}

std::istream & operator>>(std::istream & in, DoubleNode & DNode)
{
	std::cout << "Ingrese un nombre: ";
	in >> DNode.name;
	std::cout << "Ingrese un apellido: ";
	in >> DNode.lastName;
	std::cout << "Ingrese un email: ";
	in >> DNode.email;
	std::cout << "Ingrese un dia de nacimiento: ";
	in >> DNode.birthDay;
	std::cout << "Ingrese un mes de nacimiento: ";
	in >> DNode.birthMonth;
	std::cout << "Ingrese un año de nacimiento: ";
	in >> DNode.birthYear;
	return in;
}

bool DoubleNode::operator > (DoubleNode & DNode)
{
	return getAge() > DNode.getAge();
}

bool DoubleNode::operator < (DoubleNode & DNode)
{
	return getAge() > DNode.getAge();
}

DoubleNode::~DoubleNode()
{
	if (next != nullptr)
	{
		delete next;
	}
}