#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<algorithm>

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
int Donor::donate(){
    cout<< "please input $: ";
    int num;
    string tmpStr;
    getline(cin, tmpStr);
    num = stoi(tmpStr);
    this->donate(num);
    cout<<endl<<"donate succeeded! "<<endl;
    this->view();
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

    /**
     * donorLastName
     * contains only letters
     */
    while(1){
	    cout<<endl<<"original is:"<<this->donorLastName<<endl;
	    cout<<"please input your Last name: ";
	    getline(cin, tmpStr);
	    if(tmpStr == ""){
		    cout<< "Last name remains"<<endl;
		    break;
	    }
        else if(tmpStr.length() >= 20 || tmpStr.length() <= 1){
		    cout<<"length of name should be more than 1 character and less than 20 character"<<endl;
		    continue;
	    }
	    else if(any_of(tmpStr.begin(), tmpStr.end(), ::isdigit)){
		    cout<< "name should not contain digit"<<endl;
		    continue;
	    }
	    else{
		    this->donorLastName = tmpStr;
		    break;

	    }

    }

    /**
     * donorFirstName
     * contains only letters
     */
    while(1){
	    cout<<endl<<"original is:"<<this->donorFirstName<<endl;
	    cout<<"please input your Firstname: ";
	    getline(cin, tmpStr);
	    if(tmpStr.length() >= 20 || tmpStr.length() <= 1){
		    cout<<"length of name should be more than 1 character and less than 20 character"<<endl;
		    continue;
	    }
	    else if(any_of(tmpStr.begin(), tmpStr.end(), ::isdigit)){
		    cout<< "name should not contain digit"<<endl;
		    continue;
	    }
	    else if(tmpStr == ""){
		    cout<< "Last name remains"<<endl;
		    break;
	    }
	    else{
		    this->donorFirstName = tmpStr;
		    break;

	    }

    }

    /**
     * userID
     * contains at least 5 characters but no more than 10,
     * containing only letters and digits
     */
    //somecode TODO

    /**
     * password
     * contains at least 6 characters,
     * including at least one digit
     * and one character that is neither a letter nor a digit
     */
    //somecode TODO

    /**
     * age
     * must be at least 18
     */
    while(1){
	    cout<<endl<<"original is:"<<this->age<<endl;
	    cout<<"please input your age(sorry, prefer birthday, design document require): ";
	    getline(cin, tmpStr);
	    if(tmpStr == ""){
		    cout<<"age remains"<<endl;
		    break;
	    }
	    else if(!all_of(tmpStr.begin(), tmpStr.end(), ::isdigit))
		    cout<<"age should be digit"<<endl;
	    else{
		    int tmpAge = stoi(tmpStr);
		    if(tmpAge <= 13 || tmpAge >= 130 )
			    cout<<"too old or too young"<<endl;
		    else{
			    this->age = tmpAge;
			    break;
		    }

	    }

    }

    /**
     * streetNumber
     * must be positive
     */
    while(1){
	    cout<<endl<<"original is:"<<this->streetNumber<<endl;
	    cout<<"please input your street number: ";
	    getline(cin, tmpStr);
	    if(tmpStr == ""){
		    cout<<"street number remains"<<endl;
		    break;
	    }
	    else if(!all_of(tmpStr.begin(), tmpStr.end(), ::isdigit))
		    cout<<"street number should be digit"<<endl;
	    else{
		    int tmpNumber = stoi(tmpStr);
		    if(tmpNumber <= 1 || tmpNumber >= 9999 )
			    cout<<"too small or too large"<<endl;
		    else{
			    this->streetNumber = tmpNumber;
			    break;
		    }

	    }

    }

    /**
     * streetName
     * may include multiple words separated by spaces or tabs
     */
    while(1){
	    cout<<endl<<"original is:"<<this->streetName<<endl;
	    cout<<"please input your street name: ";
	    getline(cin, tmpStr);
	    if(tmpStr.length() >= 80 || tmpStr.length() <= 1){
		    cout<<"length of name should be more than 1 character and less than 80 character"<<endl;
		    continue;
	    }
	    else if(any_of(tmpStr.begin(), tmpStr.end(), ::isdigit)){
		    cout<< "name should not contain digit"<<endl;
		    continue;
	    }
	    else if(tmpStr == ""){
		    cout<< "street name remains"<<endl;
		    break;
	    }
	    else{
		    this->streetName = tmpStr;
		    break;

	    }

    }


    /**
     * town
     *  may also include multiple words separated by spaces or tabs
     */
    while(1){
	    cout<<endl<<"original is:"<<this->town<<endl;
	    cout<< "please input your town: ";
	    getline(cin, tmpStr);
	    if(tmpStr.length() >= 80 || tmpStr.length() <= 1){
		    cout<<"length of name should be more than 1 character and less than 80 character"<<endl;
		    continue;
	    }
	    else if(any_of(tmpStr.begin(), tmpStr.end(), ::isdigit)){
		    cout<< "name should not contain digit"<<endl;
		    continue;
	    }
	    else if(tmpStr == ""){
		    cout<< "town name remains"<<endl;
		    break;
	    }
	    else{
		    this->town= tmpStr;
		    break;

	    }

    }

    /**
     * state
     * C++ enum of 2-character state codes for NY, PA,
     * and the New England states only RI, NH, VT,MA, CT, ME
     */
    //somecode TODO ??does this need filter??

    /**
     * zipCode
     * contains exactly 5 digits
     */
    while(1){
	    cout<<endl<<"original is:"<<this->zipCode<<endl;
	    cout<< "please input your zip code: ";
	    getline(cin, tmpStr);
	    if(tmpStr == ""){
		    cout<<"zip code remains"<<endl;
		    break;
	    }
	    else if(!all_of(tmpStr.begin(), tmpStr.end(), ::isdigit))
		    cout<<"street number should be digit"<<endl;
	    else{
		    int tmpNumber = stoi(tmpStr);
		    if(tmpNumber <= 10000 || tmpNumber >= 99999 )
			    cout<<"too small or too large"<<endl;
		    else{
			    this->zipCode= tmpStr;
			    break;
		    }

	    }

    }

    /**
     * amountDonated
     * float, non-negative, total amount donated must not grow beyond $5,000
     */
    //TODO not here, but to exam it
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
