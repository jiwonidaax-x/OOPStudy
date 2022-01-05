#ifndef SDDS_LIBRARY_H_
#define SDDS_LIBRARY_H_
#include"Book.h"
namespace sdds {
	class Library
	{
		char m_name[31];
		Book* m_books;
		int m_sizeOfBooksArray;
		int m_addedBooks;
		void setEmpty();
		bool isEmpty()const;
		void header(const char* title)const;
		void footer()const;
	public:
		void initialize(const char* name, int noOfBooks);
		bool addBook(const char* book_title, int sku, int loanDays);
		void clear();
		void display(const char* substr);
		void display(bool overdueOnly = false)const;
		
	};

}
#endif // !SDDS_LIBRARY_H_
