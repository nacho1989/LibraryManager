#include "BookIssue.h"

using namespace std;

std::string BookIssue::GetId() {
	return this->id;
}
time_t* BookIssue::GetIssueDate() {
	return this->issueDate;
}
Book* BookIssue::GetBook() {
	return this->book;
}
Borrower* BookIssue::GetBorrower() {
	return this->borrower;
}
void BookIssue::SetId(std::string idIn) {
	id = idIn;
}
void BookIssue::SetBook(Book* bookIn) {
	book = bookIn;
}
void BookIssue::SetBorrower(Borrower* borrowerIn) {
	borrower = borrowerIn;
}

void BookIssue::SetIssueDate(time_t* timeIn)
{
	issueDate = timeIn;
}
