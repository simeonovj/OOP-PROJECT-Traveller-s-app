#include "Photos.h"
#include <iostream>


Photos::Photos(const char* photo_name)
	:photo_name(new char[strlen(photo_name) + 1])
{
	strcpy(this->photo_name, photo_name);
}

Photos::Photos(const Photos& other)
{
	copy(other);
}

Photos& Photos::operator=(Photos& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

Photos::~Photos()
{
	clear();
}

void Photos::serialize(std::ofstream& out) const
{
	out << "Photo: " << photo_name << " ";	
}

Photos::Photos(std::ifstream& in)
{
	in >> photo_name;
}

void Photos::copy(const Photos& other)
{
	photo_name = new char[strlen(other.photo_name) + 1];
	strcpy(photo_name, other.photo_name);
}

void Photos::clear()
{
	delete[] photo_name;	
	photo_name = nullptr;
}
