//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NCC
//Date:20211004
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"City.h"
#include<cstring>
using namespace std;
namespace sdds {

	City::City()
	{
		m_cityName[0] = '\0';
		m_population = -1;
	}

	City::City(const char* name, int population)
	{
		if (name != nullptr && population>-1 && name[0] != '\0')
		{
			strcpy(m_cityName, name);
			m_population = population;
		}
		else
		{
			setEmpty();
		}
	}

	void City::setEmpty()
	{
		m_cityName[0] = '\0';
		m_population = -1;
	}

	void City::setCityName(const char* name)
	{
		if (name!=nullptr)
		{
			strncpy(m_cityName, name, 30);
		}
		else
		{
			m_cityName[0] = '\0';
		}
	}

	void City::setPopulation(int population)
	{
		if (population<POPULATION)
		{
			m_population = population;
		}
		else
		{
			m_population = -1;
		}

	}

	void City::addPopulation(int population)
	{
		if (m_population < POPULATION)
		{
			m_population += population;
			if (m_population > POPULATION)
			{
				m_population = POPULATION;
			}
		
		}
		else
		{
			m_population = POPULATION;
		}
	}

	bool City::isEmpty()const
	{
		bool ok;
		if (m_cityName[0] == '\0' && m_population == -1)
		{
			ok = true;
		}
		else
		{
			ok = false;
		}
		return ok;
	}

	int City::getPeople()const
	{
		return m_population;
	}

	void City::display()const
	{
		if (isEmpty() == false)
		{
			cout << "|";
			cout.width(31);
			cout << std::left;
			cout << m_cityName;
			cout << "|";
			cout.width(12);
			cout << std::right;
			cout << m_population;
			
			cout << " | " << endl;
			
		}
		else
		{
			cout << "Invalid city" << endl;
		}

	}
}