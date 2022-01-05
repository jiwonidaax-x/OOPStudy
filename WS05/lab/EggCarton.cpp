//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211013
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================

#include <iostream>
#include "EggCarton.h"
using namespace std;
namespace sdds {

	void EggCarton::setbroken()
	{
		m_size = m_noOfEggs = -1;
	}

	EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize)
	{
		if (size%6==0 &&size<37&&size>5&&noOfEggs>-1&&noOfEggs<size+1 )
		{
			m_size = size;
			m_noOfEggs = noOfEggs;
			m_jumbo = jumboSize;
		}
		else
		{
			setbroken();
		}

	}
	ostream& EggCarton::display(std::ostream& ostr) const
	{
		if (operator bool())
		{
			int cartonWidth = m_size == 6 ? 3 : 6;
			for (int i = 0; i < m_size; i++) {
				cout << ((i < m_noOfEggs) ? (m_jumbo ? 'O' : 'o') : '~');
				if ((i + 1) % cartonWidth == 0) cout << endl;
			}
		}
		else 
		{
			cout << "Broken Egg Carton!" << endl;
		}
		return ostr;
	}

	istream& EggCarton::read(std::istream& istr)
	{	
		char input[127];		
		istr.get(input, 127,',');
		(*input == 'j' ? m_jumbo = true : m_jumbo=false);
		istr.ignore(1000, ',');
		istr >> m_size;
		istr.ignore(1000, ',');
		istr >> m_noOfEggs;

		if (m_size % 6 == 0 && m_size < 37 && m_size>5 && m_noOfEggs > -1 && m_noOfEggs < m_size + 1)
		{

		}	
		else
		{
			setbroken();
		}
		
		return istr;
	}


	EggCarton::operator bool() const
	{
		return (m_size > 0);
	}
	EggCarton::operator int() const
	{
		int ok;

		(operator bool() ? ok = m_noOfEggs : ok = -1);
		
		return ok;

	}
	EggCarton::operator double() const
	{
		double total = 0.0;
		if (operator bool())
		{
			if (m_jumbo == true)
			{
				total = (m_noOfEggs * JumboEggWieght) / 1000.0;
			}
			else if(m_jumbo == false)
			{
				total = (m_noOfEggs * RegularEggWieght) / 1000.0;
			}
		}		
		else
		{
			total = -1.0;
		}

		return total;		

	}
	EggCarton& EggCarton::operator=(int value)
	{
		if (value<m_size)
		{
			m_noOfEggs = value;
		}
		else
		{
			setbroken();
		}

		return *this;
	}
	EggCarton& EggCarton::operator+=(int value)
	{
		if (value+m_noOfEggs < m_size)
		{
			m_noOfEggs += value;
		}
		else
		{
			setbroken();
		}
		return *this;
	}
	EggCarton& EggCarton::operator+=(EggCarton& right)
	{
		if (operator bool())
		{
			m_noOfEggs += right.m_noOfEggs;
			if (m_noOfEggs>m_size)
			{
				right.m_noOfEggs = m_noOfEggs - m_size;
				m_noOfEggs = m_size;
			}
		}
		else
		{
			setbroken();
		}
		return *this;
		
	}
	bool EggCarton::operator==(const EggCarton& right) const
	{
		return (operator double() - right.operator double()>-0.001|| operator double() - right.operator double()>0.0001);
		
	}
	EggCarton& EggCarton::operator++()
	{
		if (operator bool())
		{
			m_noOfEggs++;
			if (m_noOfEggs>m_size)
			{
				setbroken();
			}
		}
		return *this;
	}
	EggCarton EggCarton::operator++(int)//후위
	{
		EggCarton local = *this;
		operator++();

		return local;

	}
	EggCarton& EggCarton::operator--()
	{
		if (operator bool()&&m_noOfEggs>0)
		{
			m_noOfEggs--;
		}
		return *this;
	}
	EggCarton EggCarton::operator--(int)//후위
	{
		EggCarton local = *this;
		operator--();

		return local;

	}
	int operator+(int left, const EggCarton& right)
	{
		
		int value=0;
		if (right.operator bool())
		{
			value=left + right.operator int();
		}
		else 
		{
			value = left;
		}
		return value;

    }
	ostream& operator<<(ostream& ostr, const EggCarton& right)
	{
		 right.display(ostr);
		 return ostr;
     }
	istream& operator>>(istream& istr, EggCarton& right)
	{
		 right.read(istr);
		 return istr;
	}

}