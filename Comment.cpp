#include "Comment.h"
#include <iostream>


Comment::Comment(const char* comment)
	:comment(new char[strlen(comment) + 1])
{
	strcpy(this->comment, comment);
}

Comment::Comment(const Comment& other)
{
	copy(other);
}

Comment& Comment::operator=(Comment& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

Comment::~Comment()
{
	clear();
}

void Comment::serialize(std::ofstream& out) const
{
	out << "Comment: " << comment << std::endl;	
}

Comment::Comment(std::ifstream& in)
{
	in >> comment;
}

void Comment::copy(const Comment& other)
{
	comment = new char[strlen(other.comment) + 1];
	strcpy(comment, other.comment);
}

void Comment::clear()
{
	delete[] comment;
	comment = nullptr;
}
