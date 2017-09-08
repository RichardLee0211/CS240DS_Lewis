#include<iostream>
#include<stdlib.h>
#include<iomanip>

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
    cout<< "added $" << addNum <<endl;
    return 0;

}

/**
 * print out balance
 *
 */
int Donor::total(){
    cout<< "$" ;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<this->amountDonated<<endl;
    return 0;

}

int Donor::add(){
    string tmpStr;

    cout<<"please input your Last name: ";
    getline(cin, tmpStr);
    if(tmpStr.length() >= 20 || tmpStr.length() <= 1)
        cout<<"length of name should be more than 1 character and less than 20 character"<<endl;
    else if(any_of(tmpStr.begin(), tmpStr.end(), ::isdigit))
        cout<< "name should not contain digit"<<endl;
    else if(tmpStr == "")
        cout<< "Last name remains"<<endl;
    else
        this->donorLastName = tmpStr;


    cout<<"please input your Firstname: ";
    getline(cin, tmpStr);
    if(tmpStr != "")
        this->donorFirstName = tmpStr;
    cout<<"please input your age(sorry, prefer birthday, design document require): ";
    getline(cin, tmpStr);
    if(tmpStr != "")
        this->age = stoi(tmpStr);
    cout<<"please input your street number: ";
    getline(cin, tmpStr);
    if(tmpStr != "")
        this->streetNumber = stoi(tmpStr);
    cout<<"please input your street name: ";
    getline(cin, tmpStr);
    if(tmpStr != "")
        this->streetName = tmpStr;
    cout<< "please input your twon: ";
    getline(cin, tmpStr);
    if(tmpStr != "")
        this->town= tmpStr;
    cout<< "please input your zip code: ";
    getline(cin, tmpStr);
    if(tmpStr != "")
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
    cout<<"now, change your infor, use return to remain same. "<< endl;
    this->add();
    return 0;
}
