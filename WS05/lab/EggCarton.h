//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211013
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_EGGCARTON_H
#define SDDS_EGGCARTON_H
#include <iostream>
namespace sdds {

	const int RegularEggWieght = 50;
	const int JumboEggWieght = 75;

   class EggCarton {
	   int m_size;
	   int m_noOfEggs;
	   bool m_jumbo;
	   void setbroken();
   public: 
	   EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
	   std::ostream& display(std::ostream& ostr) const;
	   std::istream& read(std::istream& istr);
	   operator bool() const;
	   operator int() const;
	   operator double() const;
	   EggCarton& operator=(int value);
	   EggCarton& operator+=(int value);
	   EggCarton& operator+=(EggCarton& right);
	   bool operator==(const EggCarton& right) const;
	   EggCarton& operator++();
	   EggCarton operator++(int);//후위
	   EggCarton& operator--();
	   EggCarton operator--(int);//후위
	   
   };
   int operator+(int left, const EggCarton& right);
   std::ostream& operator<<(std::ostream& ostr, const EggCarton& right);
   std::istream& operator>>(std::istream& istr, EggCarton& right);
}
#endif