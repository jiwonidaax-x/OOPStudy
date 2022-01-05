//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211001
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_BANK_H_
#define SDDS_BANK_H_
#include"Account.h"
namespace sdds {

	class Bank
	{	
		char m_name[31];
		Account* m_account;
		int m_sizeOfaccountArray;
		int m_addedAccount;
		void setEmpty();
		bool isEmpty()const;
		void header(const char* title)const;
		void head()const;
		void footer()const;
	public:
		void initialize(const char* bank_name, int noOfAccounts);
		bool addAccount(int account_number, double balance, int daysSinceLastPayment);
		void clear();	
		void display(bool intrestOnly = false)const;
	};







}

#endif // !SDDS_BANK_H_
