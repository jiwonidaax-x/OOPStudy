#pragma once
#ifndef SDDS_BASESHAPE_H_
#define SDDS_BASESHAPE_H_

#include <iostream>

namespace sdds{

	class baseShape
	{
	public:
		virtual void drawShape(std::ostream& os)const = 0;
		virtual void readShape(std::istream& in) = 0;
		virtual ~baseShape(){};

	};
	std::ostream& operator<<(std::ostream& ostr, const baseShape& baseshape);
	std::istream& operator>>(std::istream& istr, baseShape& baseshape);


}
#endif // !SDDS_BASESHAPE_H_
