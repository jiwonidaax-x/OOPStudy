//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NCC
//Date:20210921
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================

// Workshop 2:
// Version: 0.9
// Date: 2021/09/17
// Description:
// This file tests the lab section of your workshop
/////////////////////////////////////////////
#include <iostream>
#include "Fighter.h"

using namespace std;
using namespace sdds;

int main() {

	Competition mycompetition = {nullptr, 0};

	cout << "*********************************" << endl;
	cout << "Welcome to OOP244-Mortal Kombat" << endl;
	cout << "*********************************" << endl;
	int i;
	for (i = 0; i < 4; i++) {
		addFighter(mycompetition);
	}
	cout << "*********************************" << endl;
	cout << "List of fighters:" << endl;
	display(mycompetition);
	cout << "*********************************" << endl;
	cout << "Let the fights begin:" << endl;
	cout << "*********************************" << endl;
	while (mycompetition.numfighters > 1) {
		fight(mycompetition, mycompetition.fighters[0], mycompetition.fighters[1]);
		if (mycompetition.numfighters > 1) {
			cout << "*********************************" << endl;
			cout << "List of fighters Still Standing:" << endl;
			display(mycompetition);
			cout << "*********************************" << endl;
		}
	}
	cout << "*********************************" << endl;
	cout << "The winner of the competition is:" << endl;
	display(mycompetition);
	delete[] mycompetition.fighters;
	return 0;
}