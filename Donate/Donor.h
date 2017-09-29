#ifndef DONOR_H
#define DONOR_H

#include<iostream>
#include<stdlib.h>

using namespace std;

enum State{NY=0, PA, RI, NH, VT, MA, CT, ME};

class Donor{
    private:
        string donorLastName;
        string donorFirstName;
        string userID;
        string password;
        int age;
        int streetNumber;
        string streetName;
        string town;
        enum State state;
        string zipCode;
        float amountDonated;
    public:
        Donor();
        int add(int tags=0);
        int manage(); // to change some or all donor infor
        int view();
        int passwd();
        int donate(float addNum);
        int donate();
        int total();
        int quit();
        int logout();

    public:
        int setfromLine(string line);
        float getAmountDonated();
        int donorMain();
        string getUserID();
        string getPassword();
        string getAlltoLine();
        int setIDandPasswd();
        int setDonorName();
        int setAge();
        int setAddress();



};
#endif
