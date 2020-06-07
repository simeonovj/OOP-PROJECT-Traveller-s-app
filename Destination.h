#pragma once
#include <fstream>

/**
	* Class Destination
	*/
class Destination
{
public:
	/**
	* Big four
	*/
	Destination(const char* city, const char* country);
	Destination(const Destination& other);
	Destination& operator=(Destination& other);
	~Destination();

	/**
	* Serialize and deserialize for files
	*/
	void serialize(std::ofstream& out) const;
	Destination(std::ifstream& in);

	/**
	* Get method
	*/
	inline const char* GetCity() const { return city; }
	inline const char* GetCountry() const { return country; }

private:
	void copy(const Destination& other);
	void clear();

	char* city;
	char* country;
		
};

