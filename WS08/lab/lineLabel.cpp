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
#include<cstring>
#include"lineLabel.h"
using namespace std;
namespace sdds {

	lineLabel::lineLabel()
	{
		m_length = 0;
	}
	lineLabel::lineLabel( const char* label, int length):labelShape(label)
	{
		m_length = length;

	}
	void lineLabel::drawShape(std::ostream& os)const
	{
		if (m_length> 0 && label() != nullptr)
		{
			os << label() << '\n';
			for (int i = 0; i < m_length; ++i) {
				os << '=';
			}
		}
	}
	void lineLabel::readShape(std::istream& in)
	{
		labelShape::readShape(in);
		in >> m_length;
		in.ignore(1000, '\n');

	}













}