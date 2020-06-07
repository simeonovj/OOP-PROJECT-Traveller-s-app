#pragma once
#include <ostream>
#include <fstream>

class Time_period
{
public:
	Time_period(int day, int month, int year);

	void serialize(std::ofstream& out) const;
	Time_period(std::ifstream& in);

	void print();

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

