#include <vector>
#include "Registration.h"
#include "Photos.h"
#include "Comment.h"
#include "Grade.h"
#include "Time_period.h"
#include "Destination.h"

#pragma once
class System
{
private:
	System();
public:
	static System& i();
	System(const System&) = delete;
	void operator=(const System&) = delete;
	~System();

	void singup(const char* username, const char* pass, const char* email);
	void singin(const char* usermane, const char* pass, const char* email);
	void destination(const char* city, const char* country);
	Time_period DateFrom(int day, int month, int year);
	Time_period DateTo(int day, int month, int year);
	void grade(int m_grade);
	void add_comment(const char* comment);
	void add_photo(const char* photo);
	void print();
	void Help();
	void run();
	

	bool serialize(const char* m_name) const;
	bool Read(const char* m_name);
	
	

private:
	std::vector<Registation> registrations;
	std::vector<Destination> destinations;
	std::vector<Time_period> time_period;
	std::vector<Time_period> time_period2;
	std::vector<Grade> grades;
	std::vector<Comment> comments;
	std::vector<Photos> photos;
	

};

