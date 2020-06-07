#include <cstring>
#include "Registration.h"
#include <iostream>



Registation::Registation(const char* nickname, const char* pass, const char* email)
	:nickname(new char[strlen(nickname) + 1])
	, pass(new char[strlen(pass) + 1])
	,email(new char[strlen(email) +1])
{
	strcpy(this->nickname, nickname);
	strcpy(this->pass, pass);
	strcpy(this->email, email);
}

Registation::Registation(const Registation& other)
{
	copy(other);
}

Registation& Registation::operator=(Registation& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

Registation::~Registation()
{
	clear();
}

void Registation::serialize(std::ofstream& out) const
{	
	out << nickname << " ";
	out << pass << " ";
	out << email << std::endl;;	
}

Registation::Registation(std::ifstream& in)
{
	in >> nickname;
	in >> pass;
	in >> email;
}

void Registation::print()
{
	std::cout << nickname << pass << email;
}

void Registation::copy(const Registation& other)
{
	nickname = new char[strlen(other.nickname) + 1];
	strcpy(nickname, other.nickname);
	pass = new char[strlen(other.pass) + 1];
	strcpy(pass, other.pass);
	email = new char[strlen(other.email) + 1];
	strcpy(email, other.email);
}

void Registation::clear()
{
	delete[] nickname;
	delete[] pass;
	delete[] email;
	nickname = nullptr;
	pass = nullptr;
	email = nullptr;
}
