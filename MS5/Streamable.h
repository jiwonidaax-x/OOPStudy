//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211121
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#pragma once
#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_

namespace sdds {
	class Streamable
	{


	public:
		 virtual std::ostream& write(std::ostream& os = std::cout)const = 0;
		 virtual std::istream& read(std::istream& in) = 0;
		 virtual bool conIO(std::ios& io)const=0;
		 virtual operator bool() = 0;
		 virtual~Streamable() {}

	};
	std::ostream& operator<<(std::ostream& os, const Streamable& streamable);
	std::istream& operator>>(std::istream& is, Streamable& streamable);


}
#endif // SDDS_STREAMABLE_H__
