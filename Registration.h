#pragma once
#include <fstream>
class Registation
{
public:
	Registation(const char* nickname, const char* pass, const char* email);
	Registation(const Registation& other);
	Registation& operator=(Registation& other);
	~Registation();

	void serialize(std::ofstream& out) const;
	Registation(std::ifstream& in);

	void print();

	inline const char* GetNickName() const { return nickname; }
	inline const char* GetPass() const { return pass; }
	inline const char* GetEmail()const { return email; }
private:
	void copy(const Registation& other);
	void clear();

	char* nickname;
	char* pass;
	char* email;
};

