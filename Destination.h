#pragma once
#include <fstream>
class Destination
{
public:
	Destination(const char* city, const char* country);
	Destination(const Destination& other);
	Destination& operator=(Destination& other);
	~Destination();

	void serialize(std::ofstream& out) const;
	Destination(std::ifstream& in);

	void print();

	inline const char* GetCity() const { return city; }
	inline const char* GetCountry() const { return country; }

private:
	void copy(const Destination& other);
	void clear();

	char* city;
	char* country;
		
};

