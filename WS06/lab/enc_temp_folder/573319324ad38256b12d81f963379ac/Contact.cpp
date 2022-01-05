//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include<iomanip>
#include "Contact.h"
using namespace std;
namespace sdds {

    bool Contact::validPhone(int areaCode, int exchangeCode, int number)const
    {      
        int countac = 0;
        do {
            areaCode = (areaCode / 10);
            countac++;
        } while (areaCode > 0);
        
        int countec = 0;
        do {
            exchangeCode = (exchangeCode / 10);
            countec++;
        } while (exchangeCode > 0);
        
        return (countac==3 && countec == 3 && -1<number && number<10000);

    }
    void Contact::setEmpty()
    {
        m_name = nullptr;
        m_area = 0;
        m_exchangeCode = 0;
        m_number = -1;

    }
    void Contact::allocateAndCopy(const char* name)
    {
        delete[] m_name;
        //m_name = nullptr;
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
        
    }
    void Contact::extractChar(std::istream& istr, char ch)const
    {
       
        if (istr.peek() == ch)
        {              
            istr.ignore();        
        }
        else
        {
            istr.setstate(ios::failbit);
        }
    }
    std::ostream& Contact::printPhoneNumber(std::ostream& istr)const
    {
        istr << "(" << m_area << ") ";
        istr << m_exchangeCode;
        istr << "-";
        istr << setw(4) << setfill('0')<<right<<m_number;
      
        return istr;
    }
    void Contact::set(const char* name, int areaCode, int exchangeCode, int number)
    {
        delete[] m_name;
        m_name = nullptr;
        allocateAndCopy(name);
        m_area = areaCode;
        m_exchangeCode = exchangeCode;
        m_number = number;

    }
    Contact::Contact(const char* name, int areaCode, int exchangeCode, int number)
    {
        if (name!=nullptr && validPhone(areaCode, exchangeCode, number))
        {
            set(name, areaCode, exchangeCode, number);
        }
    }
    Contact::Contact()
    { 
        setEmpty();
    }
    Contact::Contact(const Contact& cnt)
    {
        if (cnt.operator bool() && validPhone(cnt.m_area, cnt.m_exchangeCode, cnt.m_number))
        {
            set(cnt.m_name, cnt.m_area, cnt.m_exchangeCode, cnt.m_number);
        }
        else
        {
            setEmpty();
        }
    }
    Contact& Contact::operator=(const Contact& cnt)
    {
        if (this != &cnt&&cnt.operator bool()&&validPhone(cnt.m_area,cnt.m_exchangeCode,cnt.m_number))
        {
            delete[] m_name;
            allocateAndCopy(cnt.m_name);
            m_area = cnt.m_area;
            m_exchangeCode = cnt.m_exchangeCode;
            m_number = cnt.m_number;
        }
        else
        {
            setEmpty();
        }
        return *this;
    }
    Contact::~Contact()
    {
        delete[] m_name;
        m_name = nullptr;

    }
    Contact::operator bool() const
    {
        return(m_name != nullptr && m_name[0] != '\0');

    }
    std::ostream& Contact::print(std::ostream& ostr, bool toFile) const
    {
        if (operator bool()&& validPhone(m_area, m_exchangeCode,m_number))
        {
            if (toFile)
            {
                ostr << setw(50)<<left<<setfill('.')<< m_name ;
       
                printPhoneNumber(ostr);               
            }
            else
            {
                ostr << m_name;
                ostr << ",";
                printPhoneNumber(ostr);
            }
        }
        return ostr;

    }
    std::istream& Contact::read(std::istream& istr)
    {
        char name[100];
        int area=0;
        int exchange=0;
        int number=0;
      

        istr. get(name,MaxNameLength,',');
        

        if (name!=nullptr)
        {
           
            extractChar(istr, ',');
            extractChar(istr, '(');
            istr >> area;
            extractChar(istr, ')');
            extractChar(istr, ' ');
            istr >> exchange;
            extractChar(istr, '-');
            istr >> number;
            extractChar(istr, '\n');
            if (validPhone(area, exchange, number))
            {
                set(name, area, exchange, number);
            }
        }
        else
        {
            istr.setstate(ios::failbit);
        }
        return istr;
    }
    std::ostream& operator<<(std::ostream& ostr, const Contact& cnt)
    {
        if (cnt.operator bool())
        {
            cnt.print(ostr);
        }
        else
        {
            cout << "Invalid Phone Record";
        }
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, Contact& cnt)
    {
        return cnt.read(istr);

   }
}
