//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211112
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstring>
#include "Menu.h"



using namespace std;

namespace sdds {
	void MenuItem::setempty()
	{
		delete[] m_menu;
		m_menu = nullptr;
	}
	MenuItem::MenuItem(const char* menu)
	{
		if (menu[0] != '\0' && menu != nullptr)
		{

			m_menu = new char[strlen(menu) + 1];
			strcpy(m_menu, menu);

		}
		else
		{
			setempty();
		}
	}
	MenuItem::MenuItem()
	{
		setempty();

	}
	MenuItem::~MenuItem()
	{

		delete[] m_menu;
		m_menu = nullptr;
	}
	MenuItem::operator bool()
	{
		return  (m_menu != nullptr);
	}
	MenuItem::operator char* ()const
	{
		return m_menu;
	}
	std::ostream& MenuItem::printMenuItem(std::ostream& ostr)const
	{
		if (m_menu == nullptr)
		{

		}
		else
		{
			ostr << m_menu << endl;
		}
		return ostr;
	}


	void Menu::setemptymenu()
	{
		//m_title = nullptr;
		for (int i = 0; i < noOfItem; i++)
		{
			delete m_menuItem[i];
		}

		noOfItem = 0;
	}
	Menu::Menu()
	{

		setemptymenu();
	}
	Menu::Menu(const char* title)
	{
		//delete[] m_title;
		m_title = new char[strlen(title) + 1];
		strcpy(m_title, title);
		setemptymenu();
	}
	Menu::~Menu()
	{
		for (int i = 0; i < noOfItem; i++)
		{
			delete m_menuItem[i];
			m_menuItem[i] = nullptr;
		}

		delete[] m_title;
		m_title = nullptr;

	}
	std::ostream& Menu::printtitle(std::ostream& ostr)const
	{
		if (m_title != nullptr)
		{
			ostr << m_title;
		}
		return ostr;
	}
	std::ostream& Menu::printentire(std::ostream& ostr)const
	{

		if (m_title != nullptr)
		{
			printtitle(ostr);
			//ostr << ":" << endl;
			ostr << endl;
		}
		for (int i = 0; i < noOfItem; i++)
		{

			ostr << setw(2) << setfill(' ') << right << i + 1 << "- ";
			m_menuItem[i]->printMenuItem(ostr);
		}
		ostr << " 0- Exit" << endl;
		ostr << "> ";
		return ostr;
	}
	unsigned int Menu::run()
	{
		unsigned int select = 0;
		printentire(cout);
		cin >> select;
		while (cin.fail())
		{
			cout << "Invalid Selection, try again: ";
			cin.clear();
			cin.ignore(2000, '\n');
			cin >> select;
		}
		while (select<0 || select >operator unsigned int())
		{
			cout << "Invalid Selection, try again: ";
			cin.clear();
			cin.ignore(2000, '\n');
			cin >> select;
		}

		return select;
	}
	unsigned int Menu::operator~()
	{
		unsigned int select = 0;
		select = run();
		return select;
	}

	Menu& Menu::operator<<(const char* menuitemContent)
	{

		if (operator unsigned int() < MAX_MENU_ITEMS + 1)
		{
			this->m_menuItem[noOfItem] = new MenuItem(menuitemContent);
			this->noOfItem++;

		}
		else
		{
			noOfItem = MAX_MENU_ITEMS;
			for (int i = 0; i < noOfItem; i++)
			{
				delete m_menuItem[i];
			}
		}

		return *this;
	}
	Menu::operator int()
	{
		return noOfItem;
	}
	Menu::operator unsigned int()
	{
		return noOfItem;
	}

	Menu::operator bool()
	{
		return(noOfItem > 0);
	}
	char* Menu::operator[](int index)const
	{
		return m_menuItem[index]->m_menu;
	}
	std::ostream& operator<<(std::ostream& ostr, const Menu& menu)
	{
		menu.printtitle(ostr);
		return ostr;
	}












}