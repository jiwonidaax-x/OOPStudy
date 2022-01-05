//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NCC
//Date:20211004
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_COUNTRY_H_
#define SDDS_COUNTRY_H_
#include"City.h"
namespace sdds {
	const int MAX_CITY = 20; //maximum number of cities

	class Country
	{
		char* m_name;//points to a dynamically allocated Cstring holding the Country name
		int m_noOfCity;//size of the dynamically allocated array of cities
		City* m_city = nullptr;//pointer to the dynamically allocated array of cities

	public:
		Country();
		Country(const char* name, int noOfCity, const City* cities);
		void setName(const char* name);
		Country& addCity(const City& c);
		Country& migrate(int people);
		void setEmpty();
		bool isEmpty()const;
		~Country();
		void display()const;

	};

}
#endif // !SDDS_COUNTRY_H_
