#pragma once
#include <iostream>
#include "Book.h";
#include "Borrower.h";

class BookIssue
{
public:
	std::string GetId();
	Book* GetBook();
	Borrower* GetBorrower();
	time_t* GetIssueDate();

	void SetId(std::string id);
	void SetBook(Book*);
	void SetBorrower(Borrower*);
	void SetIssueDate(time_t* time);
private:
	std::string id;
	time_t* issueDate;
	Book* book;
	Borrower* borrower;
};


