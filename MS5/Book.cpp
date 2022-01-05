//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211126
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstring>
#include"Book.h"
#include"Lib.h"
using namespace std;

namespace sdds{

	Book::Book():Publication()
	{
		delete[] m_name;
		m_name = nullptr;
	}

	void Book::set(int member_id)
	{
		Publication::set(member_id);
		Publication::resetDate();
	 }

	char Book::type()const
	{
		return 'B';

	 }

	std::ostream& Book::write(std::ostream& os ) const
	{
		Publication::write(os);
		if (Publication::conIO(os))
		{
			if (m_name!=nullptr)
			{
				char name[SDDS_AUTHOR_WIDTH + 1];
				strncpy(name, m_name, SDDS_AUTHOR_WIDTH);
				name[SDDS_AUTHOR_WIDTH] = '\0';
				os << " ";		
				os  << setw(15)<<setfill(' ')<<left << name;
				os << " |";
			}
		}
		else
		{
			os << '\t';		
			os << m_name;
		}
		return os;
	}
	
	std::istream& Book::read(std::istream& is)
	{

		Publication::read(is);

	

		char name[100] = {};

		if (Publication::conIO(is))
		{
			
			cout << "Author: ";
			is.ignore();
			
			is.getline(name,100, '\n');
			
			if (name == nullptr && strlen(name) > 256)
			{
				is.setstate(ios::failbit);
				
			}
			if (is)
			{
				delete[]m_name;
				m_name = nullptr;
				m_name = new char[127];
				strcpy(m_name, name);
			}
			
		}
		else
		{
			is.ignore();
			is.get(name, 100, '\n');
			if (name == nullptr)
			{
				is.setstate(ios::failbit);
				
			}
			if (is)
			{
				m_name = new char[127];
				strcpy(m_name, name);
				/*m_name = new char[SDDS_AUTHOR_WIDTH + 1];
				strncpy(m_name, name, SDDS_AUTHOR_WIDTH);
				m_name[SDDS_AUTHOR_WIDTH] = '\0';*/
			}
		}

		return is;
	}

	Book::operator bool() const
	{
		bool ok = false;
		if (m_name!=nullptr&&Publication::operator bool())
		{
			ok = true;
		}
		return ok;
	}

	//----------------rule of three-----------
	Book::~Book()
	{
		delete[] m_name;

	}

	Book::Book(const Book& book)
	{

		operator=(book);

	}

	Book& Book::operator=(const Book& book)
	{
		Publication::operator=(book);
		delete[] m_name;
		m_name = nullptr;
		if (book.m_name!=nullptr&& this != &book)
		{
			m_name = new char[strlen(book.m_name) + 1];
			strcpy(m_name, book.m_name);
		}
		return *this;
	}


	std::ostream& operator<<(std::ostream& os, const Book& book)
	{

		return book.write(os);

	}
	std::istream& operator>>(std::istream& is, Book& book)
	{
		return book.read(is);

	}






}