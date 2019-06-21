#pragma once
#include <list>
#include "Book.h"
#include "Borrower.h"
#include "BookIssue.h"
#include "mysql_connection.h"
#include <cppconn/resultset.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>


class Database
{
private:
	sql::Connection* connection;
	sql::Driver *driver;

public:
	Database();
	~Database();
	void GetBooks();
	void FindBook(std::string id);
	void AddBook(Book*);
	void UpdateBook(Book*);

	void FindBorrower(std::string id);
	void AddBorrower();
	void RemoveBorrower();
	void UpdateBorrower(Borrower*);

	void CreateIssueRecord(BookIssue*);
	std::list<BookIssue> GetBookIssues();
	BookIssue* findBookIssue(std::string id);

};

