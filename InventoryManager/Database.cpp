#include "Database.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <ctime>

using namespace std;
using namespace sql;

Database::Database() {

}

Database::~Database() {
	connection->close();
	driver->threadEnd();
}
void Database::GetBooks() {

}
void Database::FindBook(std::string id) {

	sql::PreparedStatement *stmt;
	sql::ResultSet *res;
	struct tm* time;
	try
	{
		driver = get_driver_instance();
		connection = driver->connect("tcp://127.0.0.1:3306", "root", "na@chiD3");
		connection->setSchema("inventorymanager");
		stmt = connection->prepareStatement("SELECT id, title, author, isdn, date from book where id=?");
		stmt->setString(1, id);
		res = stmt->executeQuery();

		if (res->rowsCount() == 0) {
			cout << "No Record(s) Found for Supplier";
		}
		else {
			while (res->next())
			{
				cout << "              Book ID: " << res->getString("id") << endl;
				cout << "              Title " << res->getString("title") << endl;
				cout << "              Author" << res->getString("author") << endl;
				cout << "              ISDN" << res->getString("isdn") << endl;
				cout << "              Date" << res->getString("date") << endl;				
			}
		}
	}
	catch (SQLException &e) {
		cerr << e.what();
	}

}
void Database::AddBook(Book* itemIn) {
	PreparedStatement *prep_Stmt;
	try 
	{
		driver = get_driver_instance();
		connection = driver->connect("tcp://127.0.0.1:3306", "root", "na@chiD3");
		connection->setSchema("inventorymanager");	
		int id = 0;

		prep_Stmt = connection->prepareStatement("INSERT INTO book (id, title, author, isdn, date) VALUES(?,?,?,?,?)");

		prep_Stmt->setString(1, itemIn->GetId().data());
		prep_Stmt->setString(2, itemIn->GetTitle().data());
		prep_Stmt->setString(3, itemIn->GetAuthor().data());
		prep_Stmt->setString(4, itemIn->GetISDN().data());
		char *dt = ctime(itemIn->GetDate());
		prep_Stmt->setDateTime(5, dt);

		id = prep_Stmt->executeUpdate();
		delete prep_Stmt;
		delete connection;

	}
	catch (SQLException &e) {
		cerr << e.what();
	}		
}
void Database::UpdateBook(Book* book) {
	PreparedStatement *prep_Stmt;
	try
	{
		driver = get_driver_instance();
		connection = driver->connect("tcp://127.0.0.1:3306", "root", "na@chiD3");
		connection->setSchema("inventorymanager");
		int id = 0;

		prep_Stmt = connection->prepareStatement("UPDATE book SET title=?, author=?, isdn=?, date=? WHERE id=?) VALUES(?,?,?,?,?)");

		prep_Stmt->setString(1, book->GetTitle().data());
		prep_Stmt->setString(2, book->GetAuthor().data());
		prep_Stmt->setString(3, book->GetISDN().data());
		char *dt = ctime(book->GetDate());
		prep_Stmt->setDateTime(4, dt);
		prep_Stmt->setString(5, book->GetId().data());

		id = prep_Stmt->executeUpdate();
		delete prep_Stmt;
		delete connection;

	}
	catch (SQLException &e) {
		cerr << e.what();
	}
}

void Database::FindBorrower(std::string id){

	sql::PreparedStatement *stmt;
	sql::ResultSet *res;

	try
	{
		driver = get_driver_instance();
		connection = driver->connect("tcp://127.0.0.1:3306", "root", "na@chiD3");
		connection->setSchema("inventorymanager");
		stmt = connection->prepareStatement("SELECT id,firstname, lastname from borrower where id=?");
		stmt->setString(1, id);
		res = stmt->executeQuery();

		if (res->rowsCount() == 0) {
			cout << "No Record(s) Found for Supplier";
		}
		else {
			while (res->next())
			{
				cout << "              Borrower ID: " << res->getString("id") << endl;
				cout << "              Borrower First Name " << res->getString("firstname") << endl;
				cout << "              Borrower Last Name " << res->getString("lastname") << endl;
			}
		}
	}
	catch (SQLException &e) {
		cerr << e.what();
	}
}
void Database::AddBorrower() {

}
void Database::RemoveBorrower() {

}
void Database::UpdateBorrower(Borrower* borrower) {
}

void Database::CreateIssueRecord(BookIssue* issue)
{
}

std::list<BookIssue> Database::GetBookIssues()
{
	return std::list<BookIssue>();
}

BookIssue * Database::findBookIssue(std::string id)
{
	return nullptr;
}

//bool Database::CheckSupplier(string* name, string* phone)
//{
//	sql::PreparedStatement *stmt;
//	sql::ResultSet *res;
//	
//	driver = get_driver_instance();
//	connection = driver->connect("tcp://127.0.0.1:3306", "root", "na@chiD3");
//	connection->setSchema("inventorymanager");
//	stmt = connection->prepareStatement("SELECT Count(id) from supplier where name=? and phone=?");
//	stmt->setString(1, name->data());
//	stmt->setString(2, phone->data());
//	res = stmt->executeQuery();
//	
//	if (res->rowsCount() > 0)
//		return true;
//		
//	return false;
//}

