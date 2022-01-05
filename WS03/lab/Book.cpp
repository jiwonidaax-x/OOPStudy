#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Book.h"
#include<cstring>
using namespace std;
namespace sdds {
	const double PENALTY = 1.5; // Penalty in dollars for each day a book's return is overdue
	const int MAXLOAN = 15; // Maximum number of days to loan a book witout penalty.

	void Book::setEmpty() 
	{
		m_title[0] = '\0';
		m_SKU = 0;
		m_daysOnLoan = 0;
	}
	double Book::penalty()const
	{
		double penalty;
		penalty=PENALTY*( m_daysOnLoan - MAXLOAN);
		return penalty;

	}
	void Book::set(const char* title, int sku, int daysOnLoan)
	{
		if (title[0]=='\0' || sku < 1)
		{
			setEmpty();
		}
		else
		{
			strcpy(m_title, title);
			m_title[50] = '\0';
			m_SKU = sku;
			m_daysOnLoan = daysOnLoan;
		}
	}
	bool Book::isEmpty()const
	{
		return (m_title[0] == '\0' && m_SKU == 0 && m_daysOnLoan == 0);
	}
	bool Book::hasPenalty()const
	{
		return(m_daysOnLoan > MAXLOAN);
	}
	bool Book::subTilte(const char* title)
	{
		bool ok = true;
		if (strstr(m_title, title) == NULL) {
			ok = false;
		}
		return ok;
	}
	void Book::display()const
	{
		if (isEmpty())
		{
			cout << "Invalid library book" << endl;
		}
		else {
			cout.width(49);
			cout << std::left << m_title;

			cout.width(8);
			cout << std::left << m_SKU;

			cout.width(10);
			cout << std::left << m_daysOnLoan;

			if (hasPenalty())
			{
				cout.width(7);
				cout << std::right;
				cout.precision(2);
				cout<<fixed<<penalty();
			}
			cout << endl;
		}
	}





}
