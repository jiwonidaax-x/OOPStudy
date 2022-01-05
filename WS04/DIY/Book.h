//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NCC
//Date:20211007
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include "Chapter.h"
 namespace sdds {

	 class Book
	 {
		 char* m_name;
		 int m_noOfChap;
		 Chapter* m_chapter;
	 public:
		
		 Book();
		 Book(const char* name, int noOfchap, const Chapter* chapter);
		 void setName(const char* name);
		 Book& addChapter(const char* chapter_name, int noOfPages);
		 void setEmpty();
		 bool isEmpty()const;
		 ~Book();
		 void display()const;

	 };







}
#endif // !SDDS_BOOK_H_
