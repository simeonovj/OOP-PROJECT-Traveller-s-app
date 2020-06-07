#include <cstring>
#include "Destination.h"
#include <iostream>


Destination::Destination(const char* city, const char* country)
	:city(new char[strlen(city) + 1])
	,country(new char [strlen(country) + 1])
{
	strcpy(this->city, city);
	strcpy(this->country, country);
}

Destination::Destination(const Destination& other)
{
	copy(other);
}

Destination& Destination::operator=(Destination& other)
{
	if (this != &other)
	{
		clear();
		copy(other);		
	}
	return *this;
}

Destination::~Destination()
{
	clear();
}

void Destination::serialize(std::ofstream& out) const
{	
	out << "Detinatin: " << city << ", ";
	out << country << std::endl;;
}


Destination::Destination(std::ifstream& in)
{
	in >> city;
	in >> country;
}

void Destination::copy(const Destination& other)
{
	city = new char[strlen(other.city) + 1];
	strcpy(city, other.city);
	country = new char[strlen(other.country) + 1];
	strcpy(country, other.country);
}

void Destination::clear()
{
	delete[] city;
	city = nullptr;
	delete[] country;
	country = nullptr;
}
