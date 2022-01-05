#include <iostream>
#include "Bus.h"
using namespace std;
namespace sdds {
	void Bus::outOfService()
	{
		m_seat = m_passenger = 0;
	}
	Bus::Bus(int seat, int passenger)
	{
		if (seat % 2 == 0 && seat < 41 && seat>9 && passenger > -1 && passenger < seat + 1)
		{
			m_seat = seat;
			m_passenger = passenger;
		}
		else
		{
			outOfService();
		}
	}
	

	ostream& Bus::display(ostream& ostr) const
	{

		if (operator bool())
		{
			int i, p;
			ostr.fill('_');
			ostr.width((m_seat / 2) * 3 + 4);
			ostr << "_";
			ostr << endl << "| ";
			for (i = 0, p = -1; i < (m_seat / 2); i++, ostr << "[" << ((p += 2) < m_passenger ? '2' : ((p == m_passenger) ? '1' : ' ')) << "]");
			ostr << "|_\\_" << endl;
			ostr << "| ";
			ostr.fill(' ');
			ostr.width(((m_seat / 2) * 3 - 14) / 2);
			ostr << " " << "Seneca College";
			ostr.width(((m_seat / 2) * 3 - 14) / 2 + (m_seat % 4 != 0));
			ostr << " " << "    )" << endl;
			ostr << "`---OO";
			ostr.fill('-');
			ostr.width((m_seat / 2) * 3 - 5);
			ostr << "-" << "O---'" << endl;

			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Total Fare Price: " << operator double() << endl;
		}
		else
		{
			cout << "Out of service!" << endl;
		}
		return ostr;

	}
	istream& Bus::read(istream& istr)
	{
		char input[127];
		istr.get(input, 127, ',');
		istr >> m_seat;
		istr.ignore(1000, '\n');
		istr >> m_passenger;

		if (m_seat % 2 == 0 && m_seat < 41 && m_seat>9 && m_passenger > -1 && m_passenger < m_seat + 1)
		{}
		else
		{
			outOfService();
		}

		return istr;

	}
	Bus::operator bool() const
	{
		return(m_seat>0);

	}
	Bus::operator int() const
	{
		int ok=0;	
		if (operator bool() ? ok = m_passenger : ok = -1);
		return ok;

	}
	Bus:: operator double() const
	{
		double total = 0.0;
		if (operator bool())
		{

			total = m_passenger * BUSTICKET;
		}
		else
		{
			total = -1.0;
		}

		return total;

	}
	bool Bus::operator++()
	{
		bool ok = false;
		if (operator bool()&&m_passenger!=m_seat)
		{
			m_passenger++;
			ok = true;
		}		
		return ok;

	}
	bool Bus::operator++(int)
	{
		bool ok;
		Bus local = *this;
		ok=operator++();
		return ok;
	}
	bool Bus::operator--()

	{
		bool ok = false;
		if (operator bool()&&m_passenger!=0)
		{					
			m_passenger--;
			ok = true;					
		}
		return ok;

	}
	bool Bus::operator--(int)
	{
		bool ok;
		Bus local = *this;
		ok=operator--();
		return ok;
	}
	Bus& Bus::operator=(int value)
	{
		if (value < m_seat)
		{
			m_passenger = value;
		}
		else
		{
			outOfService();
		}
		
		return *this;

	}
	Bus& Bus::operator+=(int value)
	{

		if (value + m_passenger < m_seat)
		{
			m_passenger += value;
		}
		else
		{
			outOfService();
		}
		return *this;

	}
	Bus& Bus::operator+=(Bus& right)
	{
		if (operator bool())
		{
			m_passenger += right.m_passenger;
			if (m_passenger > m_seat)
			{
				right.m_passenger = m_passenger - m_seat;
				m_passenger = m_seat;
			}
		}
		else
		{
			outOfService();
		}
		return *this;

	}
	bool Bus::operator==(const Bus& right) const
	{
		return(right.m_passenger - m_passenger == 0);

	}
	int operator+(int left, const Bus& right)
	{
		int value = 0;
		if (right.operator bool())
		{
			value = left + right.operator int();
		}
		else
		{
			value = left;
		}
		return value;

	}
	ostream& operator<<(ostream& ostr, const Bus& right)
	{
		right.display(ostr);
		return ostr;

	}
	istream& operator>>(istream& istr, Bus& right)
	{
		right.read(istr);
		return istr;
	}
}