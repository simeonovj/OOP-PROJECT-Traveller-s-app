#include "Time_period.h"
#include <iostream>

Time_period::Time_period(int day, int month, int year)
	:m_day(day)
	,m_month(month)
	,m_year(year)
{}

void Time_period::serialize(std::ofstream & out) const
{
	out << m_day << "-";
	out << m_month << "-";
	out << m_year << std::endl;
}

Time_period::Time_period(std::ifstream& in)
{
	in >> m_day;
	in >> m_month;
	in >> m_year;
}

void Time_period::print()
{
	std::cout << m_day << m_month << m_year;
}
