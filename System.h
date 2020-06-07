#include <vector>
#include "Registration.h"
#include "Photos.h"
#include "Comment.h"
#include "Grade.h"
#include "Time_period.h"
#include "Destination.h"
#pragma once

    /**
	* Class system
	*/
class System
{
private:
	System();///Constructor
public:
	///Singleton system
	static System& i();
	System(const System&) = delete;
	void operator=(const System&) = delete;
	~System();

	///Singup function
	void singup(const char* username, const char* pass, const char* email);
	///Singin function
	void singin(const char* usermane, const char* pass, const char* email);
	///Destination function
	void destination(const char* city, const char* country);
	///Time function
	Time_period DateFrom(int day, int month, int year);
	///Time function
	Time_period DateTo(int day, int month, int year);
	///Grade function
	void grade(int m_grade);
	///Comment function
	void add_comment(const char* comment);
	///Photo function
	void add_photo(const char* photo);
	///Help function
	void Help();
	///system run function
	void run();
	
	/**
	* Serialize and deserialize for files
	*/
	bool serialize(const char* m_name) const;
	bool Read(const char* m_name);
	
	

private:
	/**
	* Vectors
	*/
	std::vector<Registation> registrations;
	std::vector<Destination> destinations;
	std::vector<Time_period> time_period;
	std::vector<Time_period> time_period2;
	std::vector<Grade> grades;
	std::vector<Comment> comments;
	std::vector<Photos> photos;
	

};

