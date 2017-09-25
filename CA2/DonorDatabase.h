#ifndef DONORDATABASE_H
#define DONORDATABASE_H

#include<iostream>
#include<stdlib.h>

#include"Donor.h"

#define DONORS_MAX 1000

using namespace std;


class DonorDatabase{
private:
    Donor *donors;

public:
    DonorDatabase();
    DonorDatabase(int donorsMax);
    int login(); //call when type Login capital
    int add();
    int save();
    int load();
    int load(string filedir);
    int report();
    int quit();


};

#endif
