#pragma once
#include <fstream>

class Grade
{
public:
	Grade(int grade);

	void serialize(std::ofstream& out) const;
	Grade(std::ifstream& in);

	void print();

	inline int GetGrade() const { return m_grade; };

private:
	int m_grade;
};

