//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211025
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include<iomanip>
#include "Book.h"
using namespace std;
namespace sdds {
	//const int NoOfBookCases = 132;
	//const int NoOfShelves = 7;
	//const int MaxTitleLen = 40;
	//const int MaxAuthorLen = 25;

	//	char* m_title;
	//	char* m_name;
	//	int m_BookNum = NoOfBookCases;
	//	int m_ShelfNum = NoOfShelves;
	void Book::setEmpty()
	{
		delete[] m_name;
		delete[]m_title;
		m_title = nullptr;
		m_name = nullptr;
		m_BookNum = 0;
		m_ShelfNum = 0;
		
	}

	std::ostream& Book::printNum(std::ostream& ostr)const
	{
		ostr << m_ShelfNum<< "/" << setw(3)<<setfill('0') << right << m_BookNum;
		return ostr;
	}

	void Book::extractChar(std::istream& istr, char ch)const
	{
		if (istr.peek() == ch)
		{
			istr.ignore();
		}
		else
		{
			istr.setstate(ios::failbit);
		}

	}

	void Book::allocateAndCopy(const char* title, const char* name)
	{
		delete[] m_name;
		delete[] m_title;
		m_title = new char[strlen(title) + 1];
		strcpy(m_title, title);
	
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);

	}

	bool Book::validBook(const char* title,const char* name, int book, int shelf)
	{
		bool ok = false;

	
			if (strlen(title)<41&&strlen(name)<25)
			{
				if (book < NoOfBookCases + 1 && book>0 && shelf < NoOfShelves + 1 && shelf>0)
				{
					ok = true;
				}
			}

		return ok;
	}

	Book::operator bool() const
	{
		return(m_name != nullptr && m_title != nullptr && m_name[0]!='\0'&& m_title[0]!='\0');
	}
	Book::Book()
	{
		setEmpty();
	}
	void Book::set(const char* title,const char* name, int book, int shelf)
	{
		if (title[0]!='\0'&&name[0]!='\0')
		{
			allocateAndCopy(title, name);
			m_BookNum = book;
			m_ShelfNum = shelf;
		}
		else
		{
			delete[]m_name;
			m_name = nullptr;
			delete m_title;
			m_title = nullptr;
			setEmpty();
		}

	}
	Book::Book(const char* title,const char* name, int book, int shelf)
	{
		if (title&&name&&validBook(title, name, book, shelf))
		{
			set(title,name,book,shelf);
		}
		else
		{
			setEmpty();
		}

	}
	Book::Book(const Book& book)
	{
		if (book.operator bool() && validBook(book.m_title, book.m_name, book.m_BookNum, book.m_ShelfNum))
		{
			set(book.m_title, book.m_name, book.m_BookNum, book.m_ShelfNum);
		}
		else
		{
			setEmpty();
		}

	}
	Book& Book::operator=(const Book& book) 
	{
		if (this != &book && book.operator bool() && validBook(book.m_title, book.m_name, book.m_BookNum, book.m_ShelfNum))
		{
			set(book.m_title, book.m_name, book.m_BookNum, book.m_ShelfNum);
		}
		else
		{
			setEmpty();
		}
		return *this;

	}
	Book::~Book()
	{
		delete[] m_title;
		m_title = nullptr;
		delete[] m_name;
		m_name = nullptr;

	}
	std::ostream& Book::write(std::ostream& ostr, bool onScreen )const
	{
		
			if (onScreen)
			{
				if (m_title != nullptr)
				{
					ostr << setw(40)<<setfill(' ') << left << m_title;
					ostr << "| ";
					ostr << setw(24) << setfill(' ') << left << m_name;
					ostr << " | ";
					printNum(ostr);
				}
				else
				{
					ostr << setw(39) << setfill('.')<<left<< "Invalid Book Record ";
					ostr << " | ";
					ostr.width(24);
					ostr.fill('.');
					ostr << ".";
					ostr << " | ";
					ostr.width(5);
					ostr.fill('.');
					ostr << ".";
				}
				
			}
			else
			{
				if (m_title!=nullptr)
				{
					ostr << m_title;
					ostr << ",";
					ostr << m_name;
					ostr << ",";
					ostr << m_ShelfNum;
					ostr << "/";					
					ostr << m_BookNum;
				}
				else
				{
					ostr << "Invalid Book Record";
				}
			}	
		return ostr;		
	}
	std::istream& Book::read(std::istream& istr)
	{
		char name[MaxAuthorLen+1];
		char title[MaxTitleLen+1];
		int book = 0;
		int shelf = 0;


		istr.get(title, MaxTitleLen+1, ',');


		if (title!=nullptr)
		{
			extractChar(istr, ',');
			istr.get(name, MaxAuthorLen+1, ',');
			extractChar(istr, ',');
			istr >> shelf;
			extractChar(istr, '/');
			istr >> book;
			
			if (validBook(title,name,book, shelf))
			{
				set(title,name, book, shelf);
			}
			else
			{
				istr.setstate(ios::failbit);
			}

		}
		else
		{
			istr.setstate(ios::failbit);
		}
		return istr;

	}
	std::ostream& operator<<(std::ostream& ostr, const Book& book)
	{		
		book.write(ostr);	
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Book& book)
	{
		return book.read(istr);
	}
}