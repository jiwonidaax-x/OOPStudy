//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211109
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"

using namespace std;
namespace sdds
{
	void VehicleBasic::setEmpty() 
	{
		m_plate[0] = '\0';
		m_address[0] = '\0';
		 m_year = 0;


	}
	VehicleBasic::VehicleBasic()
	{
		setEmpty();
	}
	VehicleBasic::VehicleBasic(const char* plate, int year)
	{
		strcpy(m_plate, plate);
		m_year = year;
		strcpy(m_address, "Factory");


	}
	void VehicleBasic::NewAddress(const char* address)
	{
		if (strcmp(m_address,address))
		{

			cout << "|" << setw(8) << right << m_plate << "| ";
			cout << "|" << setw(20) << right << m_address;
			cout << " ---> ";
			cout << setw(20) << left << address << "|" << endl;
			strncpy(m_address, address, 64);
		}

	
	}
	std::ostream& VehicleBasic::write(std::ostream& os)const
	{
		os << "| " << m_year << " | " << m_plate << " | " << m_address;
		return os;


	}
	std::istream& VehicleBasic::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> m_year;
		cout << "License plate: ";
		in >> m_plate;
		cout << "Current location: ";
		in >> m_address;
		return in;


	}
	std::ostream& operator<<(std::ostream& ostr, const VehicleBasic& basic)
	{
		return basic.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, VehicleBasic& basic)
	{
		return basic.read(istr);

	}
	
	
}
