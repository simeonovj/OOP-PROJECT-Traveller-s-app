#include <vector>
#include "Registration.h"
#include "Photos.h"
#include "Comment.h"
#include "Grade.h"
#include "Time_period.h"
#include "Destination.h"
#pragma once

//Class system
class System
{
private:
	System();//Constructor
public:
	//Singleton system
	static System& i();
	System(const System&) = delete;
	void operator=(const System&) = delete;
	~System();

	void singup(const char* username, const char* pass, const char* email);//Singup function
	void singin(const char* usermane, const char* pass, const char* email);//Singin function
	void destination(const char* city, const char* country);//Destination function
	Time_period DateFrom(int day, int month, int year);//Time function
	Time_period DateTo(int day, int month, int year);//Time function
	void grade(int m_grade);//Grade function
	void add_comment(const char* comment);//Comment function
	void add_photo(const char* photo);//Photo function
	
	void Help();//Help function
	void run();//system run function
	
	//Serialize and deserialize for files 
	bool serialize(const char* m_name) const;
	bool Read(const char* m_name);
	
	

private:
	//Vectors
	std::vector<Registation> registrations;
	std::vector<Destination> destinations;
	std::vector<Time_period> time_period;
	std::vector<Time_period> time_period2;
	std::vector<Grade> grades;
	std::vector<Comment> comments;
	std::vector<Photos> photos;
	

};

