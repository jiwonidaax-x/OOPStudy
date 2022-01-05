//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211109
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds
{
	class Dumper :public VehicleBasic
	{
		double m_capacity=0.0;
		double m_cargo=0.0;
	public:
		Dumper();
		Dumper(const char* plate, int year, double capacity, const char* address);
		bool loaddCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& ostr,const Dumper& dumper);
	std::istream& operator>>(std::istream& istr, Dumper& dumper);
	
	
}
#endif
