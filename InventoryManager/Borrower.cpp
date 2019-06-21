#include "Borrower.h"

std::string Borrower::GetFirstName()
{
	return this->firstName;
}

std::string Borrower::GetLastName()
{
	return this->lastName;
}

std::string Borrower::GetFullName()
{
	return strcat(this->firstName, ' ' + this->lastName);
}

std::string Borrower::GetStudentId()
{
	return this->studentIdentification;
}

void Borrower::SetFirstName(std::string firstNameIn)
{
	int length = firstNameIn.size();

	length = (length < MAX_SIZE ? length : MAX_SIZE - 1);
	strncpy_s(firstName, firstNameIn.data(), length);
	firstName[length] = '\0';
}

void Borrower::SetLastName(std::string lastNameIn)
{
	int length = lastNameIn.size();

	length = (length < MAX_SIZE ? length : MAX_SIZE - 1);
	strncpy_s(lastName, lastNameIn.data(), length);
	lastName[length] = '\0';
}

void Borrower::SetStudentId(std::string idIn)
{
	int length = idIn.size();
	studentIdentification = idIn;
}
