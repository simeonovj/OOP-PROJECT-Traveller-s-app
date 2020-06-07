#include <fstream>
#pragma once

/**
	* Class comment
	*/
class Comment
{
public:
	/**
	* Big four
	*/
	Comment(const char* comment); 
	Comment(const Comment& other); 
	Comment& operator=(Comment& other);
	~Comment(); 

	/**
	* Serialize and deserialize for files
	*/
	void serialize(std::ofstream& out) const;
	Comment(std::ifstream& in);

	/**
	* Get method
	*/
	inline const char* GetComment() const { return comment; }

private:
	void copy(const Comment& other); 
	void clear();

	char* comment;
};

