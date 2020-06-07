#include <fstream>
#pragma once

//Class for comments
class Comment
{
public:
	//Big four
	Comment(const char* comment); // Constructor
	Comment(const Comment& other); //Copy constructor
	Comment& operator=(Comment& other); //Operator =
	~Comment(); //Destructor

	//Serialize and deserialize for files 
	void serialize(std::ofstream& out) const;
	Comment(std::ifstream& in);

	//Get mothod
	inline const char* GetComment() const { return comment; }

private:
	void copy(const Comment& other); //Copy method
	void clear(); //Clear method

	char* comment;
};

