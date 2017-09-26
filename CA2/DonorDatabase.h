#ifndef DONORDATABASE_H
#define DONORDATABASE_H

#include<iostream>
#include<stdlib.h>

#include"Donor.h"

#define DONORS_MAX 1000

using namespace std;


class DonorDatabase{
private:
    //TODO: figure out how to use this
    //donors is a pointer pointing to array
    //*donors, namely donors[0] is a pointer pointing to Donor
    //Donor* donors[];

    Donor* donors;
    int donorsNum;
    float moneyTotal;

public:
    DonorDatabase();
    DonorDatabase(int donorsMax);
    int freshMoneyTotal();

public:
    int login(); //call when type Login capital
    int add();
    int save();
    int load();
    int load(string filedir);
    int report();
    int quit();



};

#endif
