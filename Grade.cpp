#include "Grade.h"
#include <iostream>

Grade::Grade(int grade)
	:m_grade(grade)
{}

void Grade::serialize(std::ofstream & out) const
{	
	out<< "Grade: " << m_grade << std::endl;;
}

Grade::Grade(std::ifstream& in)
{
	in >> m_grade;
}

void Grade::print()
{
	std::cout << m_grade;
}
