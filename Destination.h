#pragma once
#include <fstream>

//Class for destinations
class Destination
{
public:
	//Big four
	Destination(const char* city, const char* country);//Constructor
	Destination(const Destination& other);//Copy constructor
	Destination& operator=(Destination& other);//Operator =
	~Destination();//Destructor

	//Serialize and deserialize for files 
	void serialize(std::ofstream& out) const;
	Destination(std::ifstream& in);

	//Get methods
	inline const char* GetCity() const { return city; }
	inline const char* GetCountry() const { return country; }

private:
	void copy(const Destination& other);//Copy method
	void clear();//Clear method

	char* city;
	char* country;
		
};

