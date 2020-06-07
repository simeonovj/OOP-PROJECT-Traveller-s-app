#include "Comment.h"
#include <iostream>

//Constructor
Comment::Comment(const char* comment)
	:comment(new char[strlen(comment) + 1])
{
	strcpy(this->comment, comment);
}

//Copy constructor
Comment::Comment(const Comment& other)
{
	copy(other);
}

//Operator =
Comment& Comment::operator=(Comment& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

//Destructor
Comment::~Comment()
{
	clear();
}

//Serialize method
void Comment::serialize(std::ofstream& out) const
{
	out << "Comment: " << comment << std::endl;	
}

//Deserialize method
Comment::Comment(std::ifstream& in)
{
	in >> comment;
}

//Copy method
void Comment::copy(const Comment& other)
{
	comment = new char[strlen(other.comment) + 1];
	strcpy(comment, other.comment);
}

//Clear method
void Comment::clear()
{
	delete[] comment;
	comment = nullptr;
}
