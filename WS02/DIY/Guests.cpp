//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NCC
//Date:20210921
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================

#include <iostream>
#include"Guests.h"
using namespace std;
namespace sdds {
    void read(char* str, int len) {
        if (cin.peek() == '\n') cin.ignore(); // checks the incomming character, if it is newline, it will remove it
        cin.getline(str, len);
    }
    void read(PhoneNumber& thePhoneNumber)
    {
        cout << "Enter Phone Number [area] [number]: ";
        cin >> thePhoneNumber.m_areacode;
        cin >> thePhoneNumber.m_number;
    }
    bool read(Guest& theGuest)
    {
        bool ok=false;
        cout << "Guest name: ";
 
        read(theGuest.m_name, 21);

        if (strlen(theGuest.m_name)!=0)
        {          
          read(theGuest.m_phno);
            ok = true;
        }
           
        return ok;
    }
    void print(const PhoneNumber& thePhoneNumber)
    {
        cout << "(" << thePhoneNumber.m_areacode << ") " << thePhoneNumber.m_number << endl;
        
    }
    void print(const Guest& theGuest)
    {
        cout << theGuest.m_name << ", ";
        print(theGuest.m_phno);
        
    }
    void print(const GuestList& theGuestList)
    {
        for (int i = 0; i < theGuestList.m_noOfGuests; i++)
        {
            cout << i+1 << "- ";
            print(theGuestList.m_gst[i]);
        }
    }
    void addGuest(GuestList& theGuestList, const Guest& aGuest)
    {
        Guest* n_guest = new Guest[theGuestList.m_noOfGuests + 1];

        for (int i = 0; i < theGuestList.m_noOfGuests; i++)
        {
            n_guest[i] = theGuestList.m_gst[i];
        }
   
        n_guest[theGuestList.m_noOfGuests] = aGuest;

        delete[] theGuestList.m_gst;
        theGuestList.m_gst = n_guest;
        theGuestList.m_noOfGuests++;
    }
}