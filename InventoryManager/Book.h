// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
#pragma once
#include <iostream>

// TODO: add headers that you want to pre-compile here

enum Availability {
	Available,
	Unavailable
};

enum Category {
	Dictionary,
	Encyclopedia,
	Guide,
	Health,
	History,
	Journal,
	Math,
	Religion,
	Science,
	Poetry,
	Literature
};


class Book {


public:
	std::string GetId();
	std::string GetTitle() const;
	std::string GetAuthor() const;
	std::string GetISDN() const;
	time_t* GetDate();
	Availability* GetAvailability();
	Category* GetCategory();

	void SetId(std::string id);
	void SetTitle(std::string title);
	void SetAuthor(std::string author);
	void SetISDN(std::string isdn);
	void SetDate(time_t*);
	void SetAvailability(Availability*);
	void SetCategory(Category*);
	static const int MAX_SIZE = 100;

private:
	std::string id;
	char title[MAX_SIZE];
	char author[MAX_SIZE];
	time_t* date;
	char isdn[MAX_SIZE];
	Availability* availability;
	Category* category;
};
