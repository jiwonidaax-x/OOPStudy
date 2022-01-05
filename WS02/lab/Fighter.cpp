//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NCC
//Date:20210921
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "Fighter.h"

using namespace std;
namespace sdds {
	void fighter(char* name) {
		cout << "Enter Fighter Name: ";
		cin >> name;

	}
	void fighter(int& power)
	{
		cout << "Enter Fighter Power: ";
		cin >> power;

	}
	void display(const Fighter& myFighter)
	{

		cout << "Name: " << myFighter.name << ", Power: " << myFighter.power << endl;

	}
	void display(const Competition& mycompetition)
	{
		for (int i = 0; i < mycompetition.numfighters; i++)
		{
			display(mycompetition.fighters[i]);
		}
	}
	void addFighter(Competition& myCompetition)
	{
		Fighter* n_fighter = new Fighter[myCompetition.numfighters + 1];

		for (int i = 0; i < myCompetition.numfighters; i++)
		{
			n_fighter[i] = myCompetition.fighters[i];
		}

		cout << "Enter the information of the new fighter:" << endl;

		fighter(n_fighter[myCompetition.numfighters].name);
		fighter(n_fighter[myCompetition.numfighters].power);

		delete[] myCompetition.fighters;

		myCompetition.fighters = n_fighter;
		myCompetition.numfighters++;


	}
	void removeFighter(Competition& mycompetition, const Fighter& loserFighter)
	{

		Fighter* n_fighter = new Fighter[mycompetition.numfighters - 1];

		int index;
		index = findFighter(mycompetition, loserFighter);

		if (index != -1)
		{
			for (int i = 0; i < mycompetition.numfighters; i++)
			{
				if (i == index)
				{
					for (int j = i; j < mycompetition.numfighters - 1; j++, i++)
					{
						n_fighter[j] = mycompetition.fighters[j + 1];
					}
				}
				else
				{
					n_fighter[i] = mycompetition.fighters[i];
				}
			}
		}
		mycompetition.numfighters--;
		delete[] mycompetition.fighters;
		mycompetition.fighters = n_fighter;
	}

	int findFighter(const Competition& mycompetition, const Fighter& theFighter)
	{
		int index = -1;
		for (int i = 0; i < mycompetition.numfighters; i++)
		{
			if (mycompetition.fighters[i].name == theFighter.name)
			{
				index = i;
			}

		}
		return index;



	}
	bool fight(const Fighter& f1, const Fighter& f2)
	{
		bool ok = false;
		if (f1.power > f2.power)
		{
			ok = true;
		}
		return ok;

	}
	void fight(Competition& mycompetition, Fighter& f1, Fighter& f2)
	{
		cout << "    " << f1.name << " will fight " << f2.name << "..." << endl;

		if (fight(f1, f2) == true)
		{
			cout << "    The winner => ";
			display(f1);
			removeFighter(mycompetition, f2);
		}
		else
		{
			cout << "    The winner => ";
			display(f2);
			removeFighter(mycompetition, f1);
		}

	}

}