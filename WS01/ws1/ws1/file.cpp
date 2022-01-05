#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
#include"file.h"
#include"drink.h"
using namespace std;
namespace sdds {

	Drink drink;
	FILE* fptr;
	bool openfile(const char file[]) {
		fptr=fopen(file, "r");
		return fptr != NULL;
	}

	void read(Drink* m_drink)
	{
		fscanf(fptr, "%s %d %lf %d", m_drink->name, &m_drink->volume, &m_drink->price, &m_drink->quantity);
		 
	}

	void closefile() 
	{
		if (fptr)
		{
			fclose(fptr);
		}
	}
}