//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211017
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_BUS_H
#define SDDS_BUS_H
#include <iostream>
namespace sdds {
   const double BUSTICKET = 125.34;

   class Bus {
       int m_seat;
       int m_passenger;
       void outOfService();
   public: 
       Bus(int seat=20,int passenger=0);
       std::ostream& display(std::ostream& ostr) const;
       std::istream& read(std::istream& istr);
  
       operator bool() const;
       operator int() const;
       operator double() const;
       bool operator++();
       bool operator++(int);//후위
       bool operator--();
       bool operator--(int);//후위
       Bus& operator=(int value);
       Bus& operator+=(int value);
       Bus& operator+=(Bus& right);
       bool operator==(const Bus& right) const;

   };
   int operator+(int left, const Bus& right);
   std::ostream& operator<<(std::ostream& ostr, const Bus& right);
   std::istream& operator>>(std::istream& istr, Bus& right);

   
}
#endif