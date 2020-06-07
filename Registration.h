#pragma once
#include <fstream>

/**
	* class Registation
	*/
class Registation
{
public:
	/**
	* Big four
	*/
	Registation(const char* nickname, const char* pass, const char* email);
	Registation(const Registation& other);
	Registation& operator=(Registation& other);
	~Registation();

	/**
	* Serialize and deserialize for files
	*/
	void serialize(std::ofstream& out) const;
	Registation(std::ifstream& in);

	/**
	* Get method
	*/
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

