//===========================
//name:Jiwon Choi
//email:jchoi152@myseneca.ca
//student Id:154292197
//section:NCC
//Date:20210921
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//===========================

#ifndef SDDS_GUESTS_H_
#define SDDS_GUESTS_H_

namespace sdds {

    struct PhoneNumber {
        int m_number;
        int m_areacode;
    };

    struct Guest {
        char m_name[21];
        PhoneNumber m_phno;
    };

    struct GuestList {
        Guest* m_gst;
        int m_noOfGuests;
    };

    void read(char* str, int len);
    void read(PhoneNumber& thePhoneNumber);
    bool read(Guest& theGuest);
    void print(const PhoneNumber& thePhoneNumber);
    void print(const Guest& theGuest);
    void print(const GuestList& theGuestList);
    void addGuest(GuestList& theGuestList, const Guest& aGuest);
}
#endif // !SDDS_GUESTS_H_


