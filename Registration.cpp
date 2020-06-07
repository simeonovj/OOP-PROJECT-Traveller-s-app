#include <cstring>
#include "Registration.h"
#include <iostream>


//Constructor
Registation::Registation(const char* nickname, const char* pass, const char* email)
	:nickname(new char[strlen(nickname) + 1])
	, pass(new char[strlen(pass) + 1])
	,email(new char[strlen(email) +1])
{
	strcpy(this->nickname, nickname);
	strcpy(this->pass, pass);
	strcpy(this->email, email);
}

//Copy constructor
Registation::Registation(const Registation& other)
{
	copy(other);
}

//Operator =
Registation& Registation::operator=(Registation& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

//Destrutor
Registation::~Registation()
{
	clear();
}

//Serialize method
void Registation::serialize(std::ofstream& out) const
{	
	out << nickname << " ";
	out << pass << " ";
	out << email << std::endl;;	
}

//Deserialize method
Registation::Registation(std::ifstream& in)
{
	in >> nickname;
	in >> pass;
	in >> email;
}

//Copy method
void Registation::copy(const Registation& other)
{
	nickname = new char[strlen(other.nickname) + 1];
	strcpy(nickname, other.nickname);
	pass = new char[strlen(other.pass) + 1];
	strcpy(pass, other.pass);
	email = new char[strlen(other.email) + 1];
	strcpy(email, other.email);
}

//Clear method
void Registation::clear()
{
	delete[] nickname;
	delete[] pass;
	delete[] email;
	nickname = nullptr;
	pass = nullptr;
	email = nullptr;
}
