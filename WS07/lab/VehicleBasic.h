//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211109
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>

namespace sdds
{
	class VehicleBasic
	{
		char m_plate[9] = {'\0'};
		char m_address[64] = {'\0'};
		int m_year = 0;
		void setEmpty();
	public:	
		VehicleBasic();
		VehicleBasic(const char* plate, int year);
		void NewAddress(const char* address);	
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& ostr, const VehicleBasic& basic);
	std::istream& operator>>(std::istream& istr, VehicleBasic& basic);



}

#endif