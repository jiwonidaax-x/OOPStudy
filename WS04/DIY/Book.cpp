//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NCC
//Date:20211007
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Book.h"
using namespace std;
namespace sdds {
	Book::Book()
	{
		m_chapter = nullptr;
		m_name = nullptr;
		m_noOfChap = 0;

	}
	Book::Book(const char* name, int noOfchap, const Chapter* chapter)
	{
		int flag = 0;
		for (int i = 0; i < noOfchap; i++)
		{
			if (chapter[i].isEmpty()==true)
			{
				flag = 1;
				i = noOfchap;
			}
		}
		if (name != nullptr  && noOfchap > 0 && flag!=1)
		{
			setName(name);
			m_noOfChap = noOfchap;
			m_chapter = new Chapter[m_noOfChap];
			for (int i = 0; i < m_noOfChap; i++)
			{
				m_chapter[i] = chapter[i];
			}
		}
		else
		{
			setEmpty();
		}

	}
	void Book::setName(const char* name)
	{
		if (name != nullptr && name[0] != '\0')
		{
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
		else
		{
			setEmpty();
		}

	}
	Book& Book::addChapter(const char* chapter_name, int noOfPages)
	{
		if (chapter_name != nullptr && chapter_name[0] != '\0' && noOfPages> 0 && noOfPages < 201)
		{

			Chapter* temp = new Chapter[m_noOfChap + 1];
			for (int i = 0; i < m_noOfChap; i++)
			{
				temp[i] = m_chapter[i];
			}
			temp[m_noOfChap].setName(chapter_name);
			temp[m_noOfChap].setpage(noOfPages);
			delete[]m_chapter;
			m_chapter = temp;
			m_noOfChap++;

		}
		return *this;


	}
	void Book::setEmpty()
	{
		m_name = nullptr;
		m_chapter = nullptr;
		m_noOfChap = 0;		

	}
	bool Book::isEmpty()const
	{
		bool ok = false;
		if (m_name == nullptr)
		{
			ok = true;
		}
		return ok;

	}
	Book::~Book()
	{
		delete[] m_name;
		m_name = nullptr;
		delete[] m_chapter;
		m_chapter = nullptr;

	}
	void Book::display()const
	{
		if (isEmpty() == false)
		{
			cout << "Book Name: " << m_name << endl;
			cout << "No of chapters: " << m_noOfChap << endl;
			cout << "Chapter name                                       Pages" << endl;
			for (int i = 0; i < m_noOfChap; i++)
			{
				m_chapter[i].display();
			}
		}
		else
		{
			cout << "Invalid book object" << endl;
		}
	}








}