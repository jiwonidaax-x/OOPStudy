//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211121
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstring>
#include "Publication.h"
#include "Utils.h"
#include"Lib.h"
using namespace std;

////m_title c-string ,hold diynamic title for pub
//char* m_title = nullptr;
//
////hold location
//char m_shelfld[4] = {};
//
////hold membership number-5digit||if m_membership==0 =>Available
//int m_membership = 0;
//
////serial num ID each publication
//int m_libRef = -1;
//
////In case of periodical=>publish date,In Books=>borrowed date
//Date* m_date;


namespace sdds {
	void Publication::setempty()
	{
		delete[]m_title;
		m_title = nullptr;

		m_shelfld[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date.setToToday();

	}
	Publication::Publication()
	{

		setempty(); // sets all the attributes to their default values
	}

	void Publication::set(int member_id)
	{
		// Sets the membership attribute to either zero or a five-digit integer.
		if (count(member_id) == 5)
		{
			m_membership = member_id;//if 5-digit=>checked out
		}
		else
		{
			m_membership = 0;//non-checkout
		}
	}

	void Publication::setRef(int value)
	{
		// Sets the **libRef** attribute value
		///(serial num ID each publication) m_libRef
		m_libRef = value;
	}

	void Publication::resetDate()
	{

		// Sets the date to the current date of the system.
		m_date.setToToday();
	}

	char Publication::type()const
	{
		//Returns the character 'P' to identify this object as a "Publication object"
		return 'P'; //It mean Publication object 	
	}

	bool Publication::onLoan()const
	{
		//Returns true is the publication is checkout (membership is non-zero)
		bool ok = false;
		if (m_membership != 0)
		{
			ok = true;
		}
		return ok;
	}


	Date Publication::checkoutDate()const
	{
		//Returns the date attribute
		return m_date;
	}

	bool Publication::operator==(const char* title)const
	{
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		bool ok = false;
		if (strstr(m_title, title) != nullptr)
		{
			//if m_title include in title the "strstr" returns m_title
			ok = true;
		}
		return ok;
	}

	Publication::operator const char* ()const
	{
		//Returns the title attribute

		return m_title;
	}

	int Publication::getRef()const
	{
		//Returns the libRef attirbute. 
		return m_libRef;
	}

	//---------Streamable pure virtual function implementations-----------

	bool Publication::conIO(std::ios& io)const
	{
		bool ok = false;
		if (&io == &cin || &io == &cout)
		{
			ok = true;
		}
		return ok;
	}


	std::ostream& Publication::write(std::ostream& os) const
	{
		
		if (conIO(os))
		{
			if (m_title != nullptr && m_date.errCode() == 0)
			{
				char title[SDDS_TITLE_WIDTH + 1];
				strncpy(title, m_title, SDDS_TITLE_WIDTH);
				title[SDDS_TITLE_WIDTH] = '\0';
				os << "| ";
				os << m_shelfld;
				os << " | ";
				os << setw(30) << setfill('.') << left <<title;
				os << " | ";
				if (m_membership == 0)
				{
					os << " N/A ";
				}
				else {
					os << setw(5) << m_membership;
				}
				os << " | ";
				os << m_date;
				os << " |";
			}

		}
		else {

			os << type();
			os << "\t";
			os << m_libRef;
			os << "\t";
			os << m_shelfld;
			os << "\t";
			os << m_title;
			os << "\t";
			os << m_membership;
			os << "\t";
			os << m_date;
			//os << "\t";
		}
		return os;
	}

	std::istream& Publication::read(std::istream& is)
	{

		setempty();

		char title[100] = {};
		char shelfld[127] = {};
		int membership = 0;
		int libRef = -1;
		Date date;


		if (conIO(is))
		{
			cout << "Shelf No: ";

			is >> shelfld;

			if (strlen(shelfld) != SDDS_SHELF_ID_LEN)
			{
				is.setstate(ios::failbit);

			}

			cout << "Title: ";
			if (is) {

				is.ignore();
				is.getline(title, 100, '\n');


			}

			cout << "Date: ";
			if (is) {
				is >> date;
				if (date.errCode() != 0)
				{
					is.setstate(ios::failbit);
				}
			}
			libRef = -1;

			if (is && date.errCode() == 0)
			{
				delete[] m_title;
				m_title = new char[127];
				strcpy(m_title, title);
				strcpy(m_shelfld, shelfld);
				m_membership = membership;
				m_date = date;
				m_libRef = libRef;
			}
		}
		else
		{
			is >> libRef;
			is.ignore();
			is >> shelfld;
			is.ignore();
			is.get(title, 127, '\t');

			is.ignore();
			is >> membership;
			is.ignore();
			is >> date;
			if (date.errCode() != 0)
			{
				is.setstate(ios::failbit);
			}
			if (is && date.errCode() == 0)
			{
				//delete[] m_title;
				//m_title = new char[SDDS_TITLE_WIDTH + 1];
				//strncpy(m_title, title, 30);
				//m_title[SDDS_TITLE_WIDTH] = '\0';
				//strcpy(m_shelfld, shelfld);
				//m_membership = membership;
				//m_date = date;
				//m_libRef = libRef;
				delete[] m_title;
				m_title = new char[127];
				strcpy(m_title, title);
				strcpy(m_shelfld, shelfld);
				m_membership = membership;
				m_date = date;
				m_libRef = libRef;

			}

		}


		return is;
	}

	Publication::operator bool() const
	{
		bool ok = false;
		if (m_title != nullptr && m_shelfld[0] != '\0')
		{
			ok = true;
		}
		return ok;
	}


	//rule of three---------------------------------------------------------
	Publication::Publication(const Publication& pub)
	{
		operator=(pub);

	}
	Publication& Publication::operator=(const Publication& pub)
	{

		delete[] m_title;
		m_title = nullptr;
		if (pub.m_title != nullptr && this != &pub)
		{
			m_title = new char[strlen(pub.m_title) + 1];
			strcpy(m_title, pub.m_title);
			strcpy(m_shelfld, pub.m_shelfld);
			m_membership = pub.m_membership;
			m_libRef = pub.m_libRef;
			m_date = pub.m_date;
		}

		return *this;
	}
	Publication::~Publication()
	{
		delete[] m_title;

	}

	std::ostream& operator<<(std::ostream& os, const Publication& pub)
	{
		return pub.write(os);
	}
	std::istream& operator>>(std::istream& is, Publication& pub)
	{
		return pub.read(is);
	}

}