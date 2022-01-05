//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211113
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<cstring>
#include"rectangleLabel.h"
using namespace std;
namespace sdds {

	rectangleLabel::rectangleLabel()
	{	}
	rectangleLabel::rectangleLabel(const char* c, int width, int height):labelShape(c)
	{
        m_space = height;
        m_width = width;

        int sizeOfLabel = strlen(label()) + 2;
        if (m_space < 3 && m_width < sizeOfLabel)
        {
            m_width = 0;
            m_space = 0;
        }


	}
	void rectangleLabel::drawShape(std::ostream& os)const
	{
        if (m_width > 0 && label() != nullptr && m_space> 0) {

            os << "+";

            for (int i = 0; i < m_width - 2; ++i)
            {
                os << '-';
            }
            os << "+" << "\n";




           
            os << "|";
            os << setw(m_space) << " ";
            os<< setw(m_width-m_space-2)<<left<<label();
            os << "|" << "\n";




            os << "+";

            for (int i = 0; i < m_width - 2; ++i)
            {
                os << '-';
            }
            os << "+";
        }
    
	}
	void rectangleLabel::readShape(std::istream& in)
	{
        labelShape::readShape(in);
        in >> m_width;
        in.ignore(1000, ',');
        in >> m_space;
        in.ignore(1000, '\n');

        int sizeOfLabel = strlen(label()) + 2;

        if (m_space < 3 && m_width < sizeOfLabel)
        {
            m_width = 0;
            m_space = 0;
        }


	}


}