#pragma once
#include <fstream>

//Class for registrations
class Registation
{
public:
	//Big four
	Registation(const char* nickname, const char* pass, const char* email);//Construcor
	Registation(const Registation& other);//Copy construcor
	Registation& operator=(Registation& other);//Operator =
	~Registation();//Destructor

	//Serialize and deserialize for files 
	void serialize(std::ofstream& out) const;
	Registation(std::ifstream& in);

	//Get methods
	inline const char* GetNickName() const { return nickname; }
	inline const char* GetPass() const { return pass; }
	inline const char* GetEmail()const { return email; }
private:
	void copy(const Registation& other);//Copy method
	void clear();//Clear method

	char* nickname;
	char* pass;
	char* email;
};

