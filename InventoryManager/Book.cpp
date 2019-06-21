// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include "Book.h"
#include <iostream>
using namespace std;

#pragma region Book
std::string Book::GetId() {
	return id;
}
string Book::GetTitle() const {
	return title;
}
string Book::GetAuthor() const {
	return author;
}
time_t* Book::GetDate() {
	return date;
}
string Book::GetISDN() const {
	return isdn;
}
Availability* Book::GetAvailability()
{	
	return this->availability;
}

Category* Book::GetCategory()
{
	return this->category;
}

void Book::SetId(std::string idIn) {
	id = idIn;
}
void Book::SetTitle(string titleIn) {
	int length = titleIn.size();

	length = (length < MAX_SIZE ? length : MAX_SIZE - 1);
	strncpy_s(title, titleIn.data(), length);
	title[length] = '\0';
}
void Book::SetAuthor(std::string authorIn) {
	int length = authorIn.size();

	length = (length < MAX_SIZE ? length : MAX_SIZE - 1);
	strncpy_s(author, authorIn.data(), length);
	author[length] = '\0';
}
void Book::SetISDN(string isdnIn) {
	int length = isdnIn.length();

	length = (length < MAX_SIZE ? length : MAX_SIZE - 1);
	strncpy_s(isdn, isdnIn.data(), length);
	isdn[length] = '\0';
}

void Book::SetCategory(Category* categoryIn) {
	category = categoryIn;
}

void Book::SetAvailability(Availability* availabilityIn) {
	availability = availabilityIn;
}

void Book::SetDate(time_t* dateIn) {
	date = dateIn;
}
#pragma endregion


// In general, ignore this file, but keep it around if you are using pre-compiled headers.
