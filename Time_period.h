#pragma once
#include <ostream>
#include <fstream>

//Class Time
class Time_period
{
public:
	Time_period(int day, int month, int year);//Cosntuctor

	//Serialize and deserialize for files 
	void serialize(std::ofstream& out) const;
	Time_period(std::ifstream& in);

	//Get methods
	inline int getDay() const { return m_day; }
	inline int getMonyh() const { return m_month; }
	inline int getYear() const { return m_year; }

	friend std::ostream& operator<<(std::ostream& out, const Time_period& obj)
	{
		return out << obj.m_day << " " << obj.m_month << " " << obj.m_year;
	}

private:
	int m_day;
	int m_month;
	int m_year;
};

