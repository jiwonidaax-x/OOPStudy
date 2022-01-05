//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211001
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Bank.h"
#include<cstring>
using namespace std;
namespace sdds {

	void Bank::setEmpty()
	{
		m_name[0] = '\0';
		m_account = nullptr;
		m_sizeOfaccountArray = 0;
		m_addedAccount = 0;

	}
	bool  Bank::isEmpty()const
	{
		return(m_name[0] == '\0');
	}
	void  Bank::header(const char* title)const
	{
		cout << title << endl;
		for (int i = 0; i < 41; i++)
		{
			cout << "-";
		}
		cout << endl;
		cout << ">>> " << m_name << " <<<" << endl;

		for (int i = 0; i < 41; i++)
		{
			cout << "-";
		}
		cout << endl;
		cout << "Row Accnt No       Balance  Days Interest" << endl;
		cout << "--- ---------- ------------ ---- --------" << endl;
	}
	void Bank::head()const {

		for (int i = 0; i < 40; i++)
		{
			cout << "-";
		}
		cout << endl;
		cout << ">>> " << m_name << " <<<" << endl;

		for (int i = 0; i < 40; i++)
		{
			cout << "-";
		}
		cout << endl;
		cout << "Row Accnt No       Balance  Days Interest" << endl;
		cout << "--- ---------- ------------ ---- --------" << endl;
	}
	void  Bank::footer()const
	{
		for (int i = 0; i < 41; i++)
		{
			cout << "-";
		}
		cout << endl;

	}
	void  Bank::initialize(const char* bank_name, int noOfAccounts)
	{

		if (bank_name != NULL && bank_name[0] != '\0' && noOfAccounts > 0)
		{
			strcpy(m_name, bank_name);
			m_sizeOfaccountArray = noOfAccounts;
			m_account = new Account[noOfAccounts];
			m_addedAccount = 0;
		}
		else
		{
			setEmpty();
		}

	}
	bool  Bank::addAccount(int account_number, double balance, int daysSinceLastPayment)
	{
		bool ok = false;
		if (m_addedAccount < m_sizeOfaccountArray)
		{
			m_account[m_addedAccount].set(account_number, balance, daysSinceLastPayment);
			m_addedAccount++;
			ok = true;
		}
		return ok;

	}
	void  Bank::clear()
	{
		delete[]m_account;
		m_account = nullptr;

	}

	void  Bank::display(bool intrestOnly)const
	{
		double total = 0.0;
		int j = 1;
		if (isEmpty())
		{
			cout << "Invalid Bank" << endl;
		}

		else
		{
			if (intrestOnly == true)
			{
				header("INTEREST ONLY LIST!");
				for (int i = 0; i < m_addedAccount; i++)
				{
					if (m_account[i].hasInterest())
					{
						cout.width(5);
						cout << std::left << j;
						m_account[i].display();
						j++;
						total += m_account[i].Interest();
					}
				}
			}
			else
			{
				head();
				for (int i = 0; i < m_addedAccount; i++)
				{
					cout.width(5);
					cout << std::left << i + 1;
					m_account[i].display();
					if (m_account[i].hasInterest())
					{
						total += m_account[i].Interest();
					}

				}
			}
			footer();
			cout << "              Total interest :  ";
			cout.precision(2);
			cout << fixed << total;
			cout << endl;
			cout << endl;

		}

	}

}


