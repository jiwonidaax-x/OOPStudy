#pragma once
#ifndef sdds_file_h
#define sdds_file_h
#include"drink.h"
namespace sdds {
		
	bool openfile(const char file[]);

	void read(Drink* m_drink);

	void closefile();
}
#endif // !sdds_file_h
