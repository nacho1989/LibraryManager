#pragma once
#include "Book.h"
#include "Borrower.h"
#include <list>
#include "Database.h"

class Controller
{
public:
	Database* database;

	void ViewAllBooks();
	void FindBook();
	void AddBook();
	void UpdateBook();
	void RemoveBook();

	void FindBorrower();
	void AddBorrower();
	void RemoveBorrower();
	void UpdateBorrower();


	void displayMenu();

	void FindBookIssue(std::string id);
	void IssueBook(Book*, Borrower*);
	void UpdateBorrower(std::string id);
};

