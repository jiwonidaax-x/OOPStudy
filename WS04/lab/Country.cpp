
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Country.h"
#include<cstring>
using namespace std;
namespace sdds {

	Country::Country()
	{
		m_city = nullptr;
		m_name = nullptr;
		m_noOfCity = 0;
	}

	Country::Country(const char* name, int noOfCity, const City* cities)
	{
		if (name != nullptr && cities != nullptr && noOfCity>0 && noOfCity<MAX_CITY)
		{
			setName(name);
			m_noOfCity = noOfCity;
			m_city = new City[m_noOfCity];
			for (int i = 0; i < m_noOfCity; i++)
			{
				m_city[i] = cities[i];
			}
		}
		else
		{
			setEmpty();
		}

	}

	void Country::setName(const char* name)
	{
		
		if (name != nullptr && name[0] != '\0')
		{
			m_name = new char[strlen(name)+1];
			strcpy(m_name, name);
		}
		else
		{
			setEmpty();
		}
	}

	Country& Country::addCity(const City& c)
	{
	
		if (c.isEmpty()==false)
		{
			City* temp = new City[m_noOfCity + 1];
			for (int i = 0; i < m_noOfCity; i++)
			{
				temp[i] = m_city[i];
			}
			temp[m_noOfCity] = c;

			delete[] m_city;
			m_city = temp;
			m_noOfCity++;
			
		}
		return *this;
	}

	Country& Country::migrate(int people)
	{
		if (people < POPULATION)
		{
			for (int i = 0; i < m_noOfCity; i++)
			{
				(*this).m_city[i].addPopulation(people);
			}
		}

		return *this;
	}

	void Country::setEmpty()
	{
		m_name = nullptr;
		m_city = nullptr;
		m_noOfCity = 0;
	}

	bool Country::isEmpty()const
	{
		bool ok=false;
		if (m_name==nullptr)
		{
			ok = true;
		}
		return ok;
	}

	Country::~Country()
	{
		delete[] m_name;
		m_name = nullptr;
		delete[] m_city;
		m_city = nullptr;

	}

	void Country::display()const
	{
		if (isEmpty()==false)
		{
			cout << "Country Name: "<<m_name<<endl;
			cout << "No of city: "<<m_noOfCity<<endl;
			cout.width(25);
			cout << std::left;
			cout << "City name";
			cout.width(17);
			cout << std::right;
			cout << "Population";
			cout << endl;
			for (int i = 0; i < m_noOfCity; i++)
			{
				m_city[i].display();

			}
		}
		else
		{
			cout << "Invalid country object" << endl;
		}

	}






}