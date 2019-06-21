#include "Book.h"
#include "Controller.h"
#include "Borrower.h"
#include <string>
#include <iterator>
#include <stdio.h>
#include <string.h>
#include<iostream>
#include <iomanip>

using namespace std;

void Controller::displayMenu()
{
	string selection;
	int sel;

	do {
		cout << "    ******* Business Name Here *********     " << endl;
		cout << "   ----------------------------------------  " << endl;
		cout << "                                             " << endl;
		cout << "             Book Store Home                 " << endl;
		cout << "                                             " << endl;
		cout << "   ----------------------------------------- " << endl;


		cout << "" << endl;
		cout << "       -------------------------------       " << endl;
		cout << "                 Main  Menu                  " << endl;
		cout << "       -------------------------------       " << endl;
		cout << "              1. Add Book                    " << endl;
		cout << "              2. View Book                   " << endl;
		cout << "              3. Find Book                   " << endl;
		cout << "              4. Delete Book                 " << endl;
		cout << "              5. Update Book                 " << endl;
		cout << "              6. Issue Book                  " << endl;
		cout << "              7. Issue Record                  " << endl;
		cout << "              8. Exit                        " << endl;
		cout << "" << endl;
		cin >> selection;
		sel = stoi(selection);

		switch (sel) 
		{
			case 1: AddBook();
				break;	
			case 6: FindBorrower();
				break;
		}
	} while (sel != 7);
}

void Controller::FindBookIssue(string id)
{
}

void Controller::IssueBook(Book *, Borrower *)
{
}

void Controller::UpdateBorrower(string id)
{
}


void Controller::ViewAllBooks()
{
	system("CLS");

	/*if (Controller::items.size() > 0)
	{
		for (Item& item : items)
		{
			cout << "Name: " << item.GetName() << endl;
			cout << "Description: " << item.GetDescription() << endl;
			cout << "Price: " << item.GetPrice() << endl;

			Supplier *itemSupplier = &item.GetSupplier();

			if (itemSupplier != nullptr) {
				cout << "Description: " << item.GetDescription() << endl;
				cout << "Description: " << item.GetDescription() << endl;
				cout << "Description: " << item.GetDescription() << endl;
			}
		}
	}
	else {
		cout << "No Record(s) Found";
	}*/
}

void Controller::FindBook()
{
	
	/*if (searchOption == 1) 
	{
		list<Item> matches = findItemByName();
		if (matches.size() > 0) {
			cout << "Found " << matches.size() << "Items" << endl;

			for (Item& item : matches)
			{
				cout << "Name: " << item.GetName() << endl;
				cout << "Description: " << item.GetDescription() << endl;
				cout << "Price: " << item.GetPrice() << endl;

				Supplier *itemSupplier = item.GetSupplier();

				if (itemSupplier != nullptr) {
					cout << "Description: " << item.GetDescription() << endl;
					cout << "Description: " << item.GetDescription() << endl;
					cout << "Description: " << item.GetDescription() << endl;
				}
			}
		}
		else {
			cout << "No Record(s) Found";
		}
	}
	if (searchOption == 2) {

		list<Item> matches = findItemById();
		if (matches.size() > 0) {
			cout << "Found " << matches.size() << "Items" << endl;

			for (Item& item : matches)
			{
				cout << "Name: " << item.GetName() << endl;
				cout << "Description: " << item.GetDescription() << endl;
				cout << "Price: " << item.GetPrice() << endl;

				Supplier *itemSupplier = &item.GetSupplier();

				if (itemSupplier != nullptr) {
					cout << "Description: " << item.GetDescription() << endl;
					cout << "Description: " << item.GetDescription() << endl;
					cout << "Description: " << item.GetDescription() << endl;
				}
			}
		}
		else {
			cout << "No Record(s) Found";
		}
	}*/
}

void Controller::AddBook()
{
	system("CLS");
	Book* item = new Book();
	cin.get();

	string inputValue;
	char yesOrNo[100] = "";

	cout << "Please enter Book title: "; 
	getline(cin, inputValue);
	item->SetTitle(inputValue);


	cout << "Please enter Book Author: ";
	getline(cin, inputValue);
	item->SetAuthor(inputValue);

	cout << "Please enter Book ISDN: ";
	getline(cin, inputValue);
	item->SetISDN(inputValue);


	cout << "Please enter Book Date: "; 
	getline(cin, inputValue, '\n');
	item->SetDate((time_t)stoi(inputValue));


	cout << "Would you like to Enter Supplier info? (Y/N): \n"; cin >> yesOrNo;
/*
	while (_strcmpi(yesOrNo,"Y") != 0 && _strcmpi(yesOrNo, "N") != 0)
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Entry: Would you like to Enter Supplier info? (Y/N): \n"; cin >> yesOrNo;
	}

	if (_strcmpi(yesOrNo, "Y") == 0)
	{
		Supplier* supplier = new Supplier();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string supplierName;
		string phone;
		cout << "Please Enter Supplier name: \n"; getline(cin,supplierName);
		cout << "Please Enter Supplier phone: \n"; getline(cin,phone);
		supplier->SetName(supplierName);
		supplier->SetPhone(phone);

		item->SetSupplier(supplier);
	}*/

	UUID idvar;
	UuidCreate(&idvar);
	item->SetId()
	database = new Database();
	database->AddItem(item);
}

void Controller::UpdateBook()
{
}

void Controller::RemoveBook()
{
}

void Controller::FindBorrower()
{
	system("CLS");
	cin.get();
	string name;
	cout << "Please enter Supplier name: ";
	getline(cin, name);

	database = new Database();
	Supplier* supplier = new Supplier();
	supplier->SetName(name);
	database->FindSupplier(supplier);
}

void Controller::AddBorrower()
{
}

void Controller::RemoveBorrower()
{
}

void Controller::UpdateBorrower()
{
}

