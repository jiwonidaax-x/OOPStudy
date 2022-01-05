#pragma once
#ifndef SDDS_LABELSHAPE_H_
#define SDDS_LABELSHAPE_H_
#include "baseShape.h"
#include<iostream>
namespace sdds {

	class labelShape:public baseShape
	{
		char* m_label ;
		
	protected:
		 const char* label()const;
	public:
		labelShape();
		labelShape(const char* c);
		~labelShape();
		 void readShape(std::istream& in);
		 labelShape(const labelShape& labelShape) = delete;
		 labelShape& operator=(const labelShape& labelShape) = delete;
	};

	

}
#endif // !SDDS_LABELSHAPE_H_