//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NCC
//Date:20211004
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_CITY_H_
#define SDDS_CITY_H_

namespace sdds {

	const int POPULATION = 20000;

	class City
	{
		char m_cityName[31];// holds the city name up to 30 chars
		int m_population;//number of people. A city can have zero population.

	public:
		City();
		City(const char* name, int population);
		void setEmpty();
		void setCityName(const char* name);
		void setPopulation(int population);
		void addPopulation(int population);
		bool isEmpty()const;
		int getPeople()const;
		void display()const;



	};

}
#endif // !SDDS_CITY_H_
