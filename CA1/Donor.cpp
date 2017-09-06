#include<iostream>
#include<stdlib.h>
#include "Donor.h"

using namespace std;

Donor::Donor(){
    donorLastName = "defaultLastname";
    donorFirstName = "defaultFirstname";
    age = 18;
    streetNumber = 0;
    streetName = "defaultStreetname";
    town = "defaultTown";
    zipCode = "10000";
    amountDonated = 0.00;

}

int Donor::view(){
    cout<< "donor Last name: " << this->donorLastName <<endl;
    cout<< "donor first name: " << this->donorFirstName <<endl;
    cout<< "age: "<< this->age <<endl;
    cout<< "street number: " << this->streetNumber <<endl;
    cout<< "town: " << this->town <<endl;
    cout<< "zip code: " << this->zipCode <<endl;
    cout<< "amount Donated: " << this->amountDonated <<endl;
    return 0;

}

int Donor::donate(int addNum){
    this->amountDonated += addNum;
    cout<< "added" << addNum <<endl;
    return 0;

}

/**
 * print out balance
 * TODO: print out $1020.33
 *
 */
int Donor::total(){
    cout<< "$" << this->amountDonated <<endl;
    return 0;

}

int Donor::add(){
    string tmpStr;
    cout<<"please input your Last name: ";
    cin>> tmpStr;
    if(tmpStr != "x")
        this->donorLastName = tmpStr;
    cout<<"please input your Firstname: ";
    cin>> tmpStr;
    if(tmpStr != "x")
        this->donorFirstName = tmpStr;
    cout<<"please input your age(sorry, prefer birthday, design document require): ";
    cin>> tmpStr;
    if(tmpStr != "x")
        this->age = stoi(tmpStr);
    cout<<"please input your street number: ";
    cin>> tmpStr;
    if(tmpStr != "x")
        this->streetNumber = stoi(tmpStr);
    cout<<"please input your street name: ";
    cin>> tmpStr;
    if(tmpStr != "x")
        this->streetName = tmpStr;
    cout<< "please input your twon: ";
    cin>> tmpStr;
    if(tmpStr != "x")
        this->town= tmpStr;
    cout<< "please input your zip code: ";
    cin>> tmpStr;
    if(tmpStr != "x")
        this->zipCode= tmpStr;
    cout<<"your amount donated will be $0 initially"<<endl;
    this->amountDonated = 0;
    cout<<endl;
    this->view();
    return 0;
}

int Donor::manage(){
    cout<<endl<<"your infor list below: "<<endl;
    this->view();
    cout<<"now, change your infor, use x+return to remain same. "<< endl;
    this->add();
    return 0;
}
