#pragma once
#include <iostream>

class Borrower
{
public:
	static const int MAX_SIZE = 100;

	std::string GetFirstName();
	std::string GetLastName();
	std::string GetFullName();
	std::string GetStudentId();

	void SetFirstName(std::string firstNameIn);
	void SetLastName(std::string lastNameIn);
	void SetStudentId(std::string idIn);

private :
	char firstName[MAX_SIZE];
	char lastName[MAX_SIZE];
	std::string studentIdentification;
};

