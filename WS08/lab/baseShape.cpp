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
using namespace std;
#include"baseShape.h"
namespace sdds {
	std::ostream& operator<<(std::ostream& ostr, const baseShape& baseshape)
	{
		 baseshape.drawShape(ostr);
		 return ostr;
		
	}
	std::istream& operator>>(std::istream& istr, baseShape& baseshape)
	{
		 baseshape.readShape(istr);
		 return istr;
	}
}