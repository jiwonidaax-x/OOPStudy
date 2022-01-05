//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211001
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
namespace sdds {
	class Account
	{
		int m_accNo;
		double m_balance;
		int m_days;
		void setEmpty();
		

 	public:
		double Interest()const;
		void set(int accNo, double balance, int days);
		bool isEmpty()const;
		bool hasInterest()const;
		void display()const;
	};

}
#endif // !SDDS_ACCOUNT_H_
