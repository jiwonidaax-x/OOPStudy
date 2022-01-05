#pragma once
#ifndef SDDS_LINELABEL_H_
#define SDDS_LINELABEL_H_
#include"labelShape.h"
#include <iostream>
namespace sdds {
	class lineLabel :public labelShape
	{
		int m_length = 0;

	public:
		lineLabel();
		lineLabel(const char* label, int length);
		 void drawShape(std::ostream& os)const;
		 void readShape(std::istream& in);

	};






















}
#endif // !SDDS_LINELABEL_H_