//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211109
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"
using namespace std;

namespace sdds
{
	Dumper::Dumper()
	{
		 m_capacity = 0.0;
		 m_cargo = 0.0;
	}
	Dumper::Dumper(const char* plate, int year, double capacity, const char* address) : VehicleBasic(plate, year) 
	{
		m_capacity = capacity;
		NewAddress(address);	
	}
	bool Dumper::loaddCargo(double cargo)
	{
		bool ok = true;
		if (m_cargo+cargo>m_capacity)
		{
			ok = false;
		}
		else
		{
			m_cargo += cargo;
		}
		return ok;
	}
	bool Dumper::unloadCargo()
	{
		bool ok = !(m_cargo == 0);
		m_cargo = 0;
		return ok;


	}
	std::ostream& Dumper::write(std::ostream& os)const
	{
		VehicleBasic::write(os);
		os << " | " << m_cargo << "/" << m_capacity;
		return os;


	}
	std::istream& Dumper::read(std::istream& in)
	{
		VehicleBasic::read(in);
		cout << "Capacity: ";
		in >> m_capacity;
		cout << "Cargo: ";
		in >> m_cargo;

		return in;


	}
	std::ostream& operator<<(std::ostream& ostr,const Dumper& dumper)
	{
		return dumper.write(ostr);
    }
	std::istream& operator>>(std::istream& istr, Dumper& dumper)
	{
		return dumper.read(istr);
    }

}
