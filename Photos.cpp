#include "Photos.h"
#include <iostream>

//Constructor
Photos::Photos(const char* photo_name)
	:photo_name(new char[strlen(photo_name) + 1])
{
	strcpy(this->photo_name, photo_name);
}

//Copy constructor
Photos::Photos(const Photos& other)
{
	copy(other);
}

//Operator =
Photos& Photos::operator=(Photos& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

//Destructor
Photos::~Photos()
{
	clear();
}

//Serialize method
void Photos::serialize(std::ofstream& out) const
{
	out << "Photo: " << photo_name << " ";	
}

//Deserialize method
Photos::Photos(std::ifstream& in)
{
	in >> photo_name;
}

//Copy method
void Photos::copy(const Photos& other)
{
	photo_name = new char[strlen(other.photo_name) + 1];
	strcpy(photo_name, other.photo_name);
}

//Clear method
void Photos::clear()
{
	delete[] photo_name;	
	photo_name = nullptr;
}
