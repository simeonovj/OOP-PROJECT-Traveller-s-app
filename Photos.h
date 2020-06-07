#include <fstream>
#pragma once

/**
	* Class photos
	*/
class Photos
{
public:
	/**
	* Big four
	*/
	Photos(const char* photo_name);
	Photos(const Photos& other);
	Photos& operator=(Photos& other);
	~Photos();

	/**
	* Serialize and deserialize for files
	*/
	void serialize(std::ofstream& out) const;
	Photos(std::ifstream& in);

	/**
	* Get method
	*/
	inline const char* GetPhotoName() const { return photo_name; }

private:
	void copy(const Photos& other);
	void clear();

	char* photo_name;
	
};

