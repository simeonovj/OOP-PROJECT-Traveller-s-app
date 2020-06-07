#include <fstream>
#pragma once
class Comment
{
public:
	Comment(const char* comment);
	Comment(const Comment& other);
	Comment& operator=(Comment& other);
	~Comment();

	void serialize(std::ofstream& out) const;
	Comment(std::ifstream& in);

	void print();

	inline const char* GetComment() const { return comment; }

private:
	void copy(const Comment& other);
	void clear();

	char* comment;
};

