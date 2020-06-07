#include "Grade.h"
#include <iostream>

//Constructor
Grade::Grade(int grade)
	:m_grade(grade)
{}

//Serialize method
void Grade::serialize(std::ofstream & out) const
{	
	out<< "Grade: " << m_grade << std::endl;;
}

//Deserialize method
Grade::Grade(std::ifstream& in)
{
	in >> m_grade;
}

