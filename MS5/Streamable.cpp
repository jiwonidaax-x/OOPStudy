
//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211121
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstring>
#include"Streamable.h"
using namespace std;

namespace sdds {


	std::ostream& operator<<(std::ostream& os, const Streamable& streamable)
	{
		return streamable.write(os);
	}
	std::istream& operator>>(std::istream& is, Streamable& streamable)
	{
		return streamable.read(is);
	}


}