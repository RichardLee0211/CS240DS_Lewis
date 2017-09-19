#include<iostream>
#include<stdlib.h>

using namespace std;

class Donor{
    private:
        string donorLastName;
        string donorFirstName;
        int age;
        int streetNumber;
        string streetName;
        string town;
        string zipCode;
        float amountDonated;
    public:
        Donor();
        int add(); // to add all new information
        int manage(); // to change some or all donor infor
        int view();
        int donate(int addNum);
        int donate();
        int total();
        int quit();



};
