#include "System.h"
#include <iomanip>
#include <vector>
#include <fstream>
#include <chrono>
#include <iostream>
#include "Registration.h"
#include "Photos.h"
#include "Comment.h"
#include "Grade.h"
#include "Time_period.h"
#include "Destination.h"


const int MAX_CMD_LEN = 8;
const int MAX_INPUT_LEN = 128;
const int MAX_COMMENT_LEN = 1000;

System::System()
{}

System& System::i()
{
	static System instance;
	return instance;
}

System::~System() 
{
	std::cout << "Have a nice day!";
}

void System::singup(const char* username, const char* pass, const char* email)
{
	registrations.push_back({ username, pass, email });	
}

void System::singin(const char* usermane, const char* pass, const char* email)
{
	registrations.push_back({ usermane, pass, email });
}

void System::destination(const char* city, const char* country)
{
	destinations.push_back({ city, country });
	std::cout<< "Destination: " << city << ", " << country << std::endl;
}

Time_period System::DateFrom(int day, int month, int year)
{
	time_period.push_back({ day, month, year });
	std::cout <<"Period: " << day << "-" << month << "-" << year << " ";
	return time_period.back();
}

Time_period System::DateTo(int day, int month, int year)
{
	time_period2.push_back({ day, month, year });
	std::cout << day << "-" << month << "-" << year << std::endl;
	return time_period.back();
}

//Grade function
void System::grade(int m_grade)
{
	grades.push_back({ m_grade });
	std::cout << "Grade: " << m_grade << std::endl;	
}

void System::add_comment(const char* comment)
{
	comments.push_back({ comment });
	std::cout << "Comment: " << comment << std::endl;
}

void System::add_photo(const char* photo)
{
	photos.push_back({ photo });
	std::cout << "Photo: " << photo << std::endl;
}

void System::run()
{
	char username[MAX_INPUT_LEN];
	char email[MAX_INPUT_LEN];
	char pass[MAX_INPUT_LEN];
	char input[MAX_CMD_LEN];
	char city[MAX_INPUT_LEN];
	char coutry[MAX_INPUT_LEN];
	char comment[MAX_COMMENT_LEN];
	char photo[MAX_INPUT_LEN];
	int m_grade{};
	int day_from, month_from, year_from;
	int day_to, month_to, year_to;
	do
	{
		std::cin >> input;
		if (strcmp(input, "singup") == 0)
		{
			std::cin >> username;
			std::cin >> pass;
			std::cin >> email;
			singup(username, pass, email);
			std::cout << "Registation was succsessfully." << std::endl;
			std::cout << "Now type (add_trip)." << std::endl;
			do
			{
				std::cin >> input;
				if (strcmp(input, "add_trip") == 0)
				{
					std::cout << "Enter your destination: ";
					std::cin >> city >> coutry;
					std::cout << "Enter date form: ";
					std::cin >> day_from >> month_from >> year_from;
					std::cout << "Enter date to: ";
					std::cin >> day_to >> month_to >> year_to;
					if (year_from > year_to || month_from > month_to)
					{
						std::cout << "Invalid date. Try again." << std::endl;
					}
					else
					{
						std::cout << "Enter grade: ";
						std::cin >> m_grade;
						if (m_grade < 0 || m_grade > 5)
						{
							std::cout << "Invalid grade. Try again." << std::endl;
						}
						else
						{
							std::cout << "Write comment: ";
							std::cin.ignore(MAX_COMMENT_LEN, '\n');
							std::cin.getline(comment, MAX_COMMENT_LEN);
							std::cout << "Upload photo: ";
							std::cin.ignore(MAX_COMMENT_LEN, '\n');
							std::cin.getline(photo, MAX_COMMENT_LEN);

							std::cout << std::endl;
							destination(city, coutry);
							DateFrom(day_from, month_from, year_from);
							DateTo(day_to, month_to, year_to);
							grade(m_grade);
							add_comment(comment);
							add_photo(photo);
							serialize(username);
						}
					}
				}
			} while (strcmp(input, "stop") == 0);
		}
		 else if (strcmp(input, "singin") == 0)
		 {
			std::cin >> username;
			std::cin >> pass;
			std::cin.getline(email, MAX_INPUT_LEN);
			singin(username, pass, email);
			std::cout << "succsessfully singin." << std::endl;
				do
				{
					std::cin >> input;
					if (strcmp(input, "add_trip") == 0)
					{
						std::cout << "Enter your destination: " << std::endl;
						std::cin >> city >> coutry;
						std::cout << "Enter date form: ";
						std::cin >> day_from >> month_from >> year_from;
						std::cout << "Enter date to: ";
						std::cin >> day_to >> month_to >> year_to;
						if (year_from > year_to || month_from > month_to)
						{
							std::cout << "Invalid date. Try again." << std::endl;
						}
						else
						{
							std::cout << "Enter grade: ";
							std::cin >> m_grade;
							if (m_grade < 0 || m_grade > 5)
							{
								std::cout << "Invalid grade. Try again." << std::endl;
							}
							else
							{
								std::cout << "Write comment: ";
								std::cin.ignore(MAX_COMMENT_LEN, '\n');
								std::cin.getline(comment, MAX_COMMENT_LEN);
								std::cout << "Upload photo: ";
								std::cin.ignore(MAX_COMMENT_LEN, '\n');
								std::cin.getline(photo, MAX_COMMENT_LEN);

								std::cout << std::endl;
								destination(city, coutry);
								DateFrom(day_from, month_from, year_from);
								DateTo(day_to, month_to, year_to);
								grade(m_grade);
								add_comment(comment);
								add_photo(photo);
								serialize(username);
							}
						}
					}				
				} while (strcmp(input, "stop") == 0);
		 }
		 else if (strcmp(input, "see_trip") == 0)
		 {
			std::cout << "Enter username:";
			std::cin >> username;
			Read(username);
		 }
		else if (strcmp(input, "help") == 0)
		{
			Help();
		}
		else if (strcmp(input, "exit") == 0) 
		{
			std::cout << "Did you want to Exit [y/n]? ";
			char option;
			std::cin.ignore(MAX_INPUT_LEN, '\n');
			std::cin.get(option);
			if (option == 'n' || option == 'N')
				input[0] = '\n';
		}
		else
		{
			std::cout << "Unknown command! Type 'help' for available commands." << std::endl;
			std::cin.ignore(MAX_CMD_LEN, '\n');
		}
	}
	while (strcmp(input, "exit") != 0);
}

bool System::serialize(const char* m_name) const
{
	std::ofstream out(m_name);

	if (!out) {
		std::cout << "Cannot open " << m_name << " file for writing!" << std::endl;
		return false;
	}

	size_t len;
	len = registrations.size();
	out << len;
	for (size_t i = 0; i < len; i++)
	{
		registrations[i].serialize(out);
		destinations[i].serialize(out);
		time_period[i].serialize(out);
		time_period2[i].serialize(out);
		grades[i].serialize(out);
		comments[i].serialize(out);
		photos[i].serialize(out);
	}

	out.close();
	std::cout << "Successfully saved." << std::endl;
	return true;
}

bool System::Read(const char* m_name)
{
	char c;
	std::ifstream in(m_name);
	if (in.is_open())
	{
		while (!in.eof())
		{
			c = in.get();
			if (!in.eof())
				std::cout << c;
		}
	}
	in.close();
	return true;
}

void System::Help()
{
	std::cout << "singup <username> <password> - create account" << std::endl
		<< "singin <username> <password> - singin in your account" << std::endl
		<< "When you are in your account:" << std::endl
		<< "add_trip - show your new trip. Then enter:" << std::endl
		<< "destination <city> <country> - to show where you travelled " << std::endl
		<< "comment <comment> - to write your commentars about yout trip" << std::endl
		<< "date <date form> <date to> - to show dates of your trip" << std::endl
		<< "grade <grade> - to appreciate your trip" << std::endl
		<< "photos <photo name> <file name> - to upload photos" << std::endl;
}