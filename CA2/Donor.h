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
        int setfromLine(string line);
        int add(); // to add all new information
        int manage(); // to change some or all donor infor
        int view();
        int donate(int addNum);
        int donate();
        int total();
        int quit();

    public:
        float getAmountDonated();



};
#endif
