/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211214
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================

#include "Utils.h"
namespace sdds {
	int count(int num)
	{
		int count = 0;

		while (num != 0)
		{
			num = num / 10;
			++count;
		}

		return count;
	}

}