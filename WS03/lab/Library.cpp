#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Library.h"
using namespace std;
namespace sdds {

	void Library::setEmpty()
	{
		m_name[0] = '\0';
		m_books = nullptr;
		m_sizeOfBooksArray = 0;
		m_addedBooks = 0;
	}
	bool Library::isEmpty()const
	{
		return(m_name[0] == '\0');

	}
	void Library::header(const char* title)const
	{
		for (int i = 0; i < 78; i++)
		{
			cout << "-";
		}
		cout << endl;
		cout << "***** " << m_name << " *****" << endl;
		cout << title << endl;
		for (int i = 0; i < 78; i++)
		{
			cout << "-";
		}
		cout << endl;
		cout << "Row Book title                                       SKU     loan days penalty" << endl;
		cout << "--- ------------------------------------------------ ------- --------- -------" << endl;


	}
	void Library::footer()const
	{

		for (int i = 0; i < 78; i++)
		{
			cout << "-";
		}
		cout << endl;

	}
	void Library::initialize(const char* name, int noOfBooks)
	{

		if (name != NULL && name[0] != '\0' && noOfBooks > 0)
		{
			strcpy(m_name, name);
			m_sizeOfBooksArray = noOfBooks;
			m_books = new Book[noOfBooks];
			m_addedBooks = 0;
		}
		else
		{
			setEmpty();
		}

	}
	bool Library::addBook(const char* book_title, int sku, int loanDays)
	{
		bool ok = false;
		if (m_addedBooks < m_sizeOfBooksArray)
		{
			m_books[m_addedBooks].set(book_title, sku, loanDays);
			m_addedBooks++;
			ok = true;
		}
		return ok;

	}
	void Library::clear()
	{
		delete[]m_books;
		m_books = nullptr;
	}

	void Library::display(const char* substr)
	{
		int j = 1;
		bool flag = false;
		if (isEmpty())
		{
			cout << "Invalid Library" << endl;
		}
		else
		{

			cout << ">>> Searching for: \"" << substr << "\" <<<" << endl;

			header("Substring search");

			for (int i = 0; i < m_addedBooks; i++)
			{
				if (m_books[i].subTilte(substr))
				{
					cout.width(4);
					cout << std::left << j;
					m_books[i].display();	
					flag = true;
					j++;
				}
			}
							
			if (flag==false)
			{
				cout << "No book title contains \"" << substr << "\"";
			}
					

				
			footer();

		}
	}
	void Library::display(bool overdueOnly)const
	{
		int j = 1;
		if (isEmpty())
		{
			cout << "Invalid Library" << endl;
		}
		
		else
		{
			if (overdueOnly == true)
			{
				header("Overdue Books");
				for (int i = 0; i < m_addedBooks; i++)
				{
					if (m_books[i].hasPenalty())
					{
						cout.width(4);
						cout << std::left << j;
						m_books[i].display();
						j++;
					}
				}
			}
			else
			{
				header("Books on Loan");
				for (int i = 0; i < m_addedBooks; i++)
				{
					cout.width(4);
					cout << std::left << i + 1;
					m_books[i].display();
				}
			}
			footer();
		}

	}
}


