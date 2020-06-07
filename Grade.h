#pragma once
#include <fstream>

//Class for grades
class Grade
{
public:
	Grade(int grade);//Constructor

	//Serialize and deserialize for files 
	void serialize(std::ofstream& out) const;
	Grade(std::ifstream& in);

	//Get method
	inline int GetGrade() const { return m_grade; };

private:
	int m_grade;
};

