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
#include "Account.h"
#include<cstring>
using namespace std;
namespace sdds{
	const double INTEREST_RATE = 0.285;
	void Account::setEmpty()

	{
		m_accNo = 0;
		m_balance = 0.0;
		m_days = 0;
	}
	double Account::Interest()const {
		double money;		
			money = m_days * (INTEREST_RATE / 365) * m_balance;
		return money;

	}
	void  Account::set(int accNo, double balance, int days)
	{
		if (accNo<0||days<0)
		{
			setEmpty();
		}
		else
		{
			m_accNo = accNo;
			m_balance = balance;
			m_days = days;
		}

	}
	bool  Account::isEmpty()const
	{
		return (m_accNo==0 && m_balance == 0.0 && m_days == 0);
	}
	bool  Account::hasInterest()const
	{
		return (m_days > 30);
	}
	void  Account::display()const
	{
		if (isEmpty())
		{
			cout << "Invalid Account" << endl;
		}
		else {
			cout.width(12);
			cout << std::left << m_accNo;

			cout.width(10); 
			cout.precision(2);
			cout << std::right <<fixed<< m_balance;
			cout << "  ";
			cout.width(4);
			cout << std::left << m_days;

			if (hasInterest())
			{
				cout.width(8);
				cout << std::right;
				cout.precision(2);
				cout << fixed << Interest();
			}
			cout << endl;
		}


	}












}