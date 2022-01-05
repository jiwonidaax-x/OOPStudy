#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
namespace sdds {

	class Book
	{
		char m_title[51];
		int m_SKU;
		int m_daysOnLoan;
		void setEmpty();
		double penalty()const;

	public:
		void set(const char* title, int sku, int daysOnLoan);
		bool isEmpty()const;
		bool hasPenalty()const;
		bool subTilte(const char* title);
		void display()const;
	};

}
#endif // !SDDS_BOOK_H_
