#include <fstream>
#pragma once
class Photos
{
public:
	Photos(const char* photo_name);
	Photos(const Photos& other);
	Photos& operator=(Photos& other);
	~Photos();

	void serialize(std::ofstream& out) const;
	Photos(std::ifstream& in);

	void print();

	inline const char* GetPhotoName() const { return photo_name; }

private:
	void copy(const Photos& other);
	void clear();

	char* photo_name;
	
};

