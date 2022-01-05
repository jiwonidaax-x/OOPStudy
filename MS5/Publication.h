//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211121
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#pragma once
#ifndef SDDS_PUBLICATION_H_
#define SDDS_PUBLICATION_H_
#include "Date.h"
#include<iostream>
namespace sdds {

	class Publication
	{
		//m_title c-string ,hold diynamic title for pub
		char* m_title = nullptr;

		//hold location
		char m_shelfld[5] = {'\0'};

		//hold membership number-5digit||if m_membership==0 =>Available
		int m_membership = 0;

		//serial num ID each publication
		int m_libRef = -1;

		//In case of periodical=>publish date,In Books=>borrowed date
		//Date* m_date;
		Date m_date;


	public:
		//set every attribute to zero or nullptr
		void setempty();

		//dafault constructor
		Publication();

		// Sets the membership attribute to either zero or a five-digit integer.
		virtual void set(int member_id);

		// Sets the **libRef** attribute value
		void setRef(int value);

		// Sets the date to the current date of the system.
		void resetDate();

		//Returns the character 'P' to identify this object as a "Publication object"
		virtual char type()const;

		//Returns true is the publication is checkout (membership is non-zero)
		bool onLoan()const;

		//Returns the date attribute
		Date checkoutDate()const;

		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)	
		bool operator==(const char* title)const;

		//Returns the title attribute
		operator const char* ()const;

		//Returns the libRef attirbute. 
		int getRef()const;

		bool conIO(std::ios& io)const;

		virtual std::ostream& write(std::ostream& os = std::cout) const;

		virtual std::istream& read(std::istream& is);

		operator bool() const;

		//--------------rule of three--------------
		//copy constructor
		Publication(const Publication& pub);

		Publication& operator=(const Publication& pub);

		//distructor
		virtual ~Publication();

	};
	std::ostream& operator<<(std::ostream& os, const Publication& pub);
	std::istream& operator>>(std::istream& is, Publication& pub);

}
#endif // SDDS_STREAMABLE_H__#pragma once
