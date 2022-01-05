//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include <iostream>
namespace sdds {
    const int MaxNameLength = 55;
    class Contact {
        char* m_name=nullptr; 
        int m_area=0;
        int m_exchangeCode=0;
        int m_number=0;
        void setEmpty();
        std::ostream& printPhoneNumber(std::ostream& istr)const;
        void extractChar(std::istream& istr, char ch)const;
        void allocateAndCopy(const char* name);
        bool validPhone(int areaCode, int exchangeCode, int number)const;
        
           
    public:
          
        void set(const char* name, int areaCode, int exchangeCode, int number);
        Contact(const char* name, int areaCode, int exchangeCode, int number);
        Contact();
        Contact(const Contact& cnt);
        Contact& operator=(const Contact& cnt);
        ~Contact();
        operator bool() const;
        std::ostream& print(std::ostream& ostr, bool toFile = true) const;
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& ostr, const Contact& cnt);
    std::istream& operator>>(std::istream& istr, Contact& cnt);
}
#endif // !SDDS_CONTACT_H


