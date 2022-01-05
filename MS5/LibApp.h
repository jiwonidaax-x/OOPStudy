//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
// section:NCC
//Date:20211214
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include"Menu.h"
#include"Publication.h"
#include"PublicationSelector.h"
#include"Book.h"
#include"Lib.h"
namespace sdds {
   class LibApp {

       //-------------------------------MS5-------------------------

       //file name
       char m_fname[256] = { '\0' };

       //publication pointer array when LibApp instantiated stored to m_PPA[capacity]
       Publication* m_PPA[SDDS_LIBRARY_CAPACITY] = { '\0' };

       //number of loaded into PPA 
       int m_NOLP = 0;

       //last library reference num It became primary key 
       //when new pub is added number will be added by one
       int m_LLRN = 0;
       

      



       bool m_changed = false;
       Menu m_YeNo;
       Menu m_publicationMenu = ("Choose the type of publication:");
       Menu m_mainMenu=("Seneca Library Application");
       Menu m_exitMenu=("Changes have been made to the data, what would you like to do?");
       bool confirm(const char* message);
       void load();  // prints: "Loading Data"<NEWLINE>
       void save();  // prints: "Saving Data"<NEWLINE>
       int search();  // prints: "Searching for publication"<NEWLINE>
       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */
       int search(char loan);//has a lone
       int search(int noloan);//no lone

   public:
       Publication* getPub(int libRef);
       void newPublication();
       void removePublication();
       void checkOutPub();
       LibApp();
       ~LibApp();
       LibApp(const char* fname);
       void run();



   };
}
#endif // !SDDS_LIBAPP_H



