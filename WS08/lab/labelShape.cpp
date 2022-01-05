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
#include"labelShape.h"
using namespace std;
namespace sdds{

	const char* labelShape::label()const {

		return m_label;
	}
	labelShape::labelShape()
	{
		m_label = nullptr;
	}
	labelShape::labelShape(const char* c)
	{
		m_label = new char[strlen(c) + 1];
		strcpy(m_label, c);
	}
	labelShape::~labelShape()
	{
		delete[] m_label;
		m_label = nullptr;
	}
	void labelShape::readShape(std::istream& in)
	{
		char Cstr[50];
		in.get(Cstr, 50, ',');
		delete[] m_label;
		m_label = new char[strlen(Cstr) + 1];
		strcpy(m_label, Cstr);
		in.ignore(1000, ',');
	}

}