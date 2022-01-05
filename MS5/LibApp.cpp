//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211214
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
//I didn't write down my signature, so I deducted it and submit it again with my signature.

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include<istream>
#include <fstream>
#include <ctime>
#include <cstring>
#include "LibApp.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	bool LibApp::confirm(const char* message)
	{
		bool flag = 0;
		Menu temp(message);
		temp << "Yes";
		if (temp.run() == 1)
		{
			flag = 1;
		}
		return flag;
	}
	LibApp::~LibApp()
	{

		for (int i = 0; i < m_NOLP; i++)
		{
			delete m_PPA[i];
			m_PPA[i] = nullptr;
		}

	}
	void LibApp::load()
	{

		//print loading data for eading
		cout << "Loading Data" << endl;
		//open data file for reading 
		ifstream infile(m_fname);
		Publication* p = nullptr;
		char type{};
		//read all the publications in dynamic instances pointed by the ppa array
		for (int i = 0; i < 1000; i++) {

			p = nullptr;
			infile.get(type);
			infile.ignore();

			if (type == 'P')
				p = new Publication();
			else if (type == 'B')
				p = new Book();
			if (infile) {
				// Then extract the object from the file stream and add one to the NOLP. 
				if (p) {
					infile >> *p;
					infile.ignore();
					m_PPA[m_NOLP] = p;
					m_NOLP++;
					m_LLRN = m_PPA[i]->getRef();
				}

			}
			else
			{
				delete p;
				p = nullptr;
			}

		}

	}

	void LibApp::save()
	{
		cout << "Saving Data" << endl;
		ofstream file(m_fname);

		for (int i = 0; i < m_NOLP; i++)
		{
			if (m_PPA[i]->getRef() != 0)
			{
				file << *m_PPA[i] << endl;
			}
		}
	}

	void LibApp::newPublication()
	{
		if (m_NOLP == SDDS_LIBRARY_CAPACITY)
		{
			cout << "Library is at its maximum capacity!" << endl;
		}
		else {
			cout << "Adding new publication to the library" << endl;
			int selection = m_publicationMenu.run();
			if (selection == 0)
			{
				cout << "Aborted!" << endl;
			}
			else {
				Publication* pub = {};

				if (selection == 2) {
					pub = new Publication();
					cin >> *pub;
				}
				else if (selection == 1) {
					pub = new Book();
					cin >> *pub;
				}

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "Aborted!" << endl;
				}

				else
				{
					if (confirm("Add this publication to the library?") == true)
					{
						m_PPA[m_NOLP] = pub;
						m_LLRN++;
						m_PPA[m_NOLP]->setRef(m_LLRN);
						m_NOLP++;
						m_changed = true;


						cout << "Publication added" << endl;
					}
					else
					{
						cout << "Aborted!" << endl;
					}
				}

			}

		}

	}

	int LibApp::search()
	{
		int retVal=0;
		char title[256];
		Publication* p = nullptr;
		PublicationSelector ps("Select one of the following found matches:", 15);
		int selection = m_publicationMenu.run();
		if (selection == 0)
		{
			cout << "Aborted!" << endl;
		}
		else
		{
		
			cout << "Publication Title: ";
			
			//cin.clear();
			cin.ignore();
			cin.getline(title, sizeof(title), '\n');
		
			if (cin.fail())
			{
				cout << "Aborted!" << endl;
			}
			if (selection == 1)
			{
				if (title==NULL)
				{
					
					//cin.clear();
					for (int i = 0; i < m_NOLP; i++)
					{
						if (m_PPA[i]->type() == 'B')
							ps << m_PPA[i];
					}
				}
				else {
					
					for (int i = 0; i < m_NOLP; i++)
					{
						if (strstr(*m_PPA[i], title) && m_PPA[i]->type() == 'B')
							ps << m_PPA[i];
					}
				}
			}
			else if (selection == 2)
			{
				if (title == NULL)
				{
					
					//cin.clear();
					for (int i = 0; i < m_NOLP; i++)
					{
						if (m_PPA[i]->type() == 'B')
							ps << m_PPA[i];
					}
				}
				else {
					
					for (int i = 0; i < m_NOLP; i++)
					{
						if (strstr(*m_PPA[i], title) && m_PPA[i]->type() == 'P')
							ps << m_PPA[i];
					}
				}
			}

			if (ps) {
				ps.sort();
				
				int ref = ps.run(); // display the publications and select one
				if (ref) {
					p = getPub(ref);
					cout << *p << endl;
					retVal = ref;
				}
				else {
					cout << "Aborted!" << endl;
					retVal = -1;
				}
			}
			else {
				cout << "No matches found! " << endl;
				retVal = -1;
			}
		}
		return retVal;
	}


	int LibApp::search(char loan)
	{
		int retVal = 0;
		char title[256];
		Publication* p = nullptr;
		PublicationSelector ps("Select one of the following found matches:", 15);
		int selection = m_publicationMenu.run();
		if (selection == 0)
		{
			cout << "Aborted!" << endl;
		}
		else
		{
			
			cout << "Publication Title: ";
			cin.ignore();
			cin.getline(title, sizeof(title), '\n');
			
			if (cin.fail())
			{
				cout << "Aborted!" << endl;
			}
			if (selection == 1)
			{
				if (title == NULL)
				{
				
					//cin.clear();
					for (int i = 0; i < m_NOLP; i++)
					{
						if (m_PPA[i]->onLoan() == true && m_PPA[i]->type() == 'B')
							ps << m_PPA[i];
					}
				}
				else {
				
					for (int i = 0; i < m_NOLP; i++)
					{
						if (strstr(*m_PPA[i], title) && m_PPA[i]->onLoan() == true && m_PPA[i]->type() == 'B')
							ps << m_PPA[i];
					}
				}
			}
			else if (selection == 2)
			{
				if (title == NULL)
				{
					
					//cin.clear();
					for (int i = 0; i < m_NOLP; i++)
					{
						if (m_PPA[i]->onLoan() == true && m_PPA[i]->type() == 'P')
							ps << m_PPA[i];
					}
				}
				else {
					
					for (int i = 0; i < m_NOLP; i++)
					{
						if (strstr(*m_PPA[i], title) && m_PPA[i]->onLoan() == true && m_PPA[i]->type() == 'P')
							ps << m_PPA[i];
					}
				}
			}

			if (ps) {
				ps.sort();
			
				int ref = ps.run(); // display the publications and select one
				if (ref) {
					p = getPub(ref);
					cout << *p << endl;
					retVal = ref;
				}
				else {
					cout << "Aborted!"<<endl;
					retVal = -1;
				}
			}
			else {
				cout << "No matches found! " << endl;
				retVal = -1;
			}
		}
		return retVal;
	}
	int LibApp::search(int noloan)
	{
		int retVal = 0;
		char title[256];
		Publication* p = nullptr;
		PublicationSelector ps("Select one of the following found matches:", 15);
		int selection = m_publicationMenu.run();
		if (selection == 0)
		{
			cout << "Aborted!" << endl;
		}
		else
		{			
			cout << "Publication Title: ";
			cin.ignore();
			cin.getline(title, sizeof(title),'\n');
		
			if (cin.fail())
			{
				cout << "Aborted!" << endl;
			}
			if (selection == 1)
			{
				if (title == NULL)
				{
		
					for (int i = 0; i < m_NOLP; i++)
					{
						if (m_PPA[i]->onLoan() == false&& m_PPA[i]->type() == 'B')
							ps << m_PPA[i];
					}
				}
				else {
				
					for (int i = 0; i < m_NOLP; i++)
					{
						if (strstr(*m_PPA[i], title) && m_PPA[i]->onLoan() == false && m_PPA[i]->type() == 'B')
							ps << m_PPA[i];
					}
				}
			}
			else if (selection == 2)
			{
				if (title == NULL)
				{
					
					for (int i = 0; i < m_NOLP; i++)
					{
						if (m_PPA[i]->onLoan() == false && m_PPA[i]->type() == 'P')
							ps << m_PPA[i];
					}
				}
				else {
				
					for (int i = 0; i < m_NOLP; i++)
					{
						if (strstr(*m_PPA[i], title) && m_PPA[i]->onLoan() == false && m_PPA[i]->type() == 'P')
							ps << m_PPA[i];
					}
				}
			}

			if (ps) {
				ps.sort();
				
				int ref = ps.run(); // display the publications and select one
				if (ref) {
					p = getPub(ref);
					cout << *p << endl;
					retVal = ref;
				}
				else {
					cout << "Aborted!" << endl;
					retVal = -1;
				     }
			}
			else {
				cout << "No matches found! " << endl;
				
				retVal = -1;
			}
		}
		return retVal;
	}

	Publication* LibApp::getPub(int libRef)
	{
		Publication* pub = nullptr;
		for (int i = 0; i < m_NOLP; i++)
		{
			if (m_PPA[i]->getRef() == libRef)
			{
				pub = m_PPA[i];
			}
		}
		return pub;
	}



	void LibApp::returnPub()
	{
		int ref;
		Publication* pub = nullptr;
		float money=0.0;
		int totalDay = 0;
		Date today;
		ref = search('L');
		if (ref != -1)
		{
			if (confirm("Return Publication?") == true)
			{
				pub = getPub(ref);
				
				totalDay = today - pub->checkoutDate(); 
				if (totalDay>15)
				{
					totalDay = totalDay - 15;
					money = 0.5 * totalDay;
					cout << "Please pay $";
					cout<<fixed<<setprecision(2) << money;
					cout << " penalty for being ";
					cout << totalDay;
					cout << " days late!" << endl;
				}
				pub->set(0);
				m_changed = true;
				cout << "Publication returned" << endl;
			}
		}
			

	}

	void LibApp::checkOutPub()
	{
		int ref = 0;
		Publication* pub = nullptr;
		cout << "Checkout publication from the library" << endl;
		ref = search(1);
		if (ref!=-1)
		{
			if (confirm("Check out publication?") == true)
			{
				int num;
				cout << "Enter Membership number: ";
				cin >> num;
				while (count(num) != 5)
				{
					cout << "Invalid membership number, try again: ";
					cin >> num;
				}

				pub = getPub(ref);
				pub->set(num);

				m_changed = true;
				cout << "Publication checked out" << endl;
			}
			else
			{
				cout << "Aborted!" << endl;
			}
		}
		
	}



	void LibApp::removePublication()
	{
		int ref = 0;
		Publication* pub = nullptr;
		cout << "Removing publication from library" << endl;
		ref=search();
		if (ref!=-1)
		{
			if (confirm("Remove this publication from the library?") == true)
			{
				pub = getPub(ref);
				pub->setRef(0);
				delete pub;
				m_changed = true;
				cout << "Publication removed" << endl;
			}
		}

	}

	//////////////////////////////////////////////////////////////////////////////////////////////

	LibApp::LibApp()
	{
		m_changed = false;
		m_publicationMenu << "Book" << "Publication";
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

		load();

	}
	LibApp::LibApp(const char* fname)
	{
		strcpy(m_fname, fname);
		m_changed = false;
		m_YeNo << "Yes";
		m_publicationMenu << "Book" << "Publication";
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

		load();
	}
	void LibApp::run()
	{
		unsigned int m_select = ~m_mainMenu;

		bool flag = 0;
		while (flag == 0)
		{
			while (m_select != 0)
			{
				if (m_select == 1)
				{
					newPublication();
					cout << endl;
					m_select = ~m_mainMenu;
				}
				else if (m_select == 2)
				{
					removePublication();
					cout << endl;
					m_select = ~m_mainMenu;

				}
				else if (m_select == 3)
				{
					checkOutPub();
					cout << endl;
					m_select = ~m_mainMenu;
				}
				else if (m_select == 4)
				{
					returnPub();
					cout << endl;
					m_select = ~m_mainMenu;

				}
			}
			if (m_changed == false)
			{
				flag = 1;
			}
			else
			{
				unsigned int e_select = ~m_exitMenu;

				if (e_select == 1)
				{
					save();
					cout << endl;
					flag = 1;
				}
				else if (e_select == 2)
				{
					cout << endl;
					m_mainMenu.run();
				}
				else if (e_select == 0)
				{
					confirm("This will discard all the changes are you sure?");
					cout << endl;
					flag = 1;
				}
				
			}
		}

		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;

	}

}


