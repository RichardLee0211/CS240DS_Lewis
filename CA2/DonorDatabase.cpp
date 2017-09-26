#include<stdio.h>
#include<fstream>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>

#include"DonorDatabase.h"
#include"Donor.h"
#include"util.h"

using namespace std;

DonorDatabase::DonorDatabase(){
    //donors[0], donor[1] will construct automatically,
    //using default constructor
    this->donors = new Donor[DONORS_MAX];
    this->donorsNum = 0;
    this->moneyTotal = 0;
};

DonorDatabase::DonorDatabase(int donorsMax){
    this->donors = new Donor[donorsMax];
    this->donorsNum = 0;
    this->moneyTotal = 0;
};

int DonorDatabase::login(){
    //TODO
    return 0;
};

int DonorDatabase::add(){
    //TODO
    return 0;
};

int DonorDatabase::save(){
    //TODO
    return 0;
};

int DonorDatabase::load(){
    string filedir;
    printf("please input database file: ");
    getline(cin, filedir);
    this->load(filedir);
    return 0;
};

/**
 * TODO: going throgh a very hard time,
 * could find many faults. U could do it better
 */
int DonorDatabase::load(string filedir){
    ifstream ifs(filedir, ifs.binary | ifs.in );
    if(!ifs.is_open())
        cout<<"failed to open file"<<endl;

    int i = 0;
    while(!ifs.eof()){
        string line;
        getline(ifs, line);
        if(line == "") break;
        cout<<line<<endl;
        this->donors[i].setfromLine(line);
        i++;
        //if(i>=donorsMax ||i>=DONORS_MAX) break; //TODO: make donorsMax global
        if(i>=DONORS_MAX) break;
    }
    this->donorsNum = i;
    this->freshMoneyTotal();
    ifs.close();

    return 0;
};

int DonorDatabase::report(){
    this->freshMoneyTotal();
    cout<<"we have "<<this->donorsNum<<" in out company."<<endl;
    cout<< "we got about $" ;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<this->moneyTotal<<endl;
    return 0;
};

int DonorDatabase::quit(){
    //TODO
    return 0;
};

int DonorDatabase::freshMoneyTotal(){
    float tmpMoneyTotal = 0.0;
    for(int i=0; i<this->donorsNum; i++){
        tmpMoneyTotal += this->donors[i].getAmountDonated();
    }
    this->moneyTotal = tmpMoneyTotal;

    return 0;
};
