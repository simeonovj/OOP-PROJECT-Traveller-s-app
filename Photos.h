#include <fstream>
#pragma once

//Class for photos
class Photos
{
public:
	//Big four
	Photos(const char* photo_name);//Construcor
	Photos(const Photos& other);//Copy constructor
	Photos& operator=(Photos& other);//Operator =
	~Photos();//Destrucot

	//Serialize and deserialize for files 
	void serialize(std::ofstream& out) const;
	Photos(std::ifstream& in);

	//Get method
	inline const char* GetPhotoName() const { return photo_name; }

private:
	void copy(const Photos& other);//Copy method
	void clear();//Clear method

	char* photo_name;
	
};

