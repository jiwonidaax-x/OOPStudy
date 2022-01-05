//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211112
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H__
#include <iostream>
namespace sdds
{
	const unsigned int MAX_MENU_ITEMS = 20;

	class Menu;

	class MenuItem
	{

		char* m_menu = nullptr;
		friend class Menu;
		void setempty();
		MenuItem(const char* menu);
		MenuItem();
		~MenuItem();
		operator bool();
		operator char* ()const;
		std::ostream& printMenuItem(std::ostream& ostr)const;
	};
	//std::ostream& operator<<(std::ostream& ostr, const MenuItem& menuitem);


	class Menu
	{
		void setemptymenu();
		char* m_title = nullptr;

		MenuItem* m_menuItem[MAX_MENU_ITEMS] = { nullptr };
		int noOfItem = 0;

	public:
		std::ostream& printtitle(std::ostream& ostr)const;
		Menu();
		Menu(const char* title);
		~Menu();
		unsigned int operator~();
		std::ostream& printentire(std::ostream& ostr)const;
		unsigned int run();
		Menu& operator<<(const char* menuitemContent);
		operator int();
		operator unsigned int();
		operator bool();
		char* operator[](int index)const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Menu& menu);
}

#endif // !SDDS_MENU_H_





