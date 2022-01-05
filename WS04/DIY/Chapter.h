//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NCC
//Date:20211007
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_CHAPTER_H_
#define SDDS_CHAPTER_H_
namespace sdds {
	

	class Chapter
	{
		char m_name[50];
		int m_page;

	public:
		Chapter();
		Chapter(const char* name, int page);
		void setEmpty();
		void setName(const char* name);
		void setpage(int page);
		bool isEmpty()const;
		int getPage()const;
		void display()const;

	};








}
#endif // !SDDS_CHAPTER_H_
