#pragma once
#ifndef SDDS_RECTANGLELABEL_H_
#define SDDS_RECTANGLELABEL_H_
#include<iostream>
#include "labelShape.h"
namespace sdds {
	class rectangleLabel:public labelShape
	{
		int m_space = 0;
		int m_width = 0;

	public:
		rectangleLabel();
		rectangleLabel(const char* c, int width, int height);
		void drawShape(std::ostream& os)const;
		void readShape(std::istream& in);

	};




















}
#endif // !SDDS_RECTANGLELABEL_H_
