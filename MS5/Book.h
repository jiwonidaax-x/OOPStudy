
//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211126
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include "Publication.h"
namespace sdds{


	class Book:public Publication
	{
		char* m_name = nullptr;

	public:
	
		Book();

		virtual void set(int member_id);
		
		virtual char type()const;

		virtual std::ostream& write(std::ostream& os = std::cout) const;

		virtual std::istream& read(std::istream& is);

		operator bool() const;

		//----------------rule of three-----------
		virtual ~Book();
	
		Book(const Book& book);

		Book& operator=(const Book& book);

	};
	 std::ostream& operator<<(std::ostream& os, const Book& book);
	std::istream& operator>>(std::istream& is, Book& book);


}
#endif // !SDDS_BOOK_H_
