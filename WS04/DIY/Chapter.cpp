//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NCC
//Date:20211007
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include <iomanip>
#include"Chapter.h"
using namespace std;
namespace sdds {

	Chapter::Chapter()
	{
		m_name[0] = '\0';
		m_page = 0;

	}
	Chapter::Chapter(const char* name, int page)
	{
		if (name != nullptr && page> 0 && name[0] != '\0')
		{
			setName(name);
			setpage(page);
		}
		else
		{
			setEmpty();
		}

	}
	void Chapter::setEmpty()
	{
		m_name[0] = '\0';
		m_page = 0;

	}
	void Chapter::setName(const char* name)
	{
		if (name != nullptr)
		{
			strcpy(m_name, name);
		}
		else
		{
			m_name[0] = '\0';
		}

	}
	void Chapter::setpage(int page)
	{
		if (page>0&& page<201)
		{
			m_page = page;
		}
		else
		{
			setEmpty();
		}

	}
	bool Chapter::isEmpty()const
	{
		bool ok;
		if (m_name[0] == '\0' && m_page == 0)
		{
			ok = true;
		}
		else
		{
			ok = false;
		}
		return ok;

	}
	int Chapter::getPage()const
	{
		return m_page;
	}
	void Chapter::display()const
	{
		cout.width(50);		
		cout.fill('.');
		cout << std::left;
		cout<< m_name;
		cout.width(4);
		cout.fill(' ');
		cout << std::right;
		cout<< m_page;	  
		cout << endl;
	}










}