//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211025
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
namespace sdds {
	const int NoOfBookCases = 132;
	const int NoOfShelves = 7;
	const int MaxTitleLen = 40;
	const int MaxAuthorLen = 25;

	class Book
	{
		char* m_title=nullptr;
		char* m_name = nullptr;
		int m_BookNum = NoOfBookCases;
		int m_ShelfNum = NoOfShelves;
		void setEmpty();
		std::ostream& printNum(std::ostream& ostr)const;
		void extractChar(std::istream& istr, char ch)const;
		void allocateAndCopy(const char* title,const char* name);
		bool validBook(const char* title, const char* name, int book, int shelf);

	

	public:

		Book(); 
		void set(const char* title,const char* name, int book, int shelf);
		Book(const char* title,const char* name, int book, int shelf);
		Book(const Book& book);
		Book& operator=(const Book& book);
		~Book();
		operator bool() const;
		std::ostream& write(std::ostream& ostr, bool onScreen = true)const;
		std::istream& read(std::istream& istr);
		

	};
	std::ostream& operator<<(std::ostream& ostr, const Book& book);
	std::istream& operator>>(std::istream& istr, Book& book);

}
#endif // !SDDS_CONTACT_H