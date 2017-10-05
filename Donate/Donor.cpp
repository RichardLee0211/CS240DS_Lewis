#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<algorithm>
#include<vector>

#include "Donor.h"
#include"util.h"

using namespace std;

Donor::Donor(){
    this->donorLastName = "defaultLastname";
    this->donorFirstName = "defaultFirstname";
    this->userID = "richard";
    this->password = "abcd";
    this->age = 18;
    this->streetNumber = 0;
    this->streetName = "defaultStreetname";
    this->town = "defaultTown";
    this->state = NY;
    this->zipCode = "10000";
    this->amountDonated = 0.00;

}

int Donor::setfromLine(string line){
    string delim = " ";
    vector<string> attri;
    SplitString(line, attri, delim);
    this->donorFirstName = attri[0];
    this->donorLastName= attri[1];
    this->userID = attri[2];
    this->password = attri[3];
    this->age = stoi(attri[4]);
    this->streetNumber = stoi(attri[5]);
    this->streetName = attri[6];
    this->town = attri[7];
    this->state = strtoState(attri[8]);
    this->zipCode = attri[9];
    this->amountDonated = atof(attri[10].c_str());
    attri.clear();
    return 0;
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

int Donor::passwd(){
    string tmpPasswd;
    string newPasswd;
    string newPasswd2;
    cout<<"please input your original passwd: ";
    cin>>tmpPasswd;
    if(tmpPasswd != this->password){
        cout<<"wrong password!!"<<endl;
        return 1;
    }
    cout<<"welcome, please input your new password: ";
    cin>>newPasswd;
    cout<<"please input new password again: ";
    cin>>newPasswd2;
    if(newPasswd != newPasswd2){
        cout<<"2 new passwd didn't match!!"<<endl;
        cout<<"fail to change passwd"<<endl;
        return 1;
    }else{
        this->password = newPasswd;
        cout<<"your passwd has been changed"<<endl;
        return 0;

    }

};

int Donor::donate(){
    cout<< "please input $: ";
    float num;
    string tmpStr;
    getline(cin, tmpStr);
    if(tmpStr == ""){
        cout<<"quit donate"<<endl;
        return -1;
    }
    //TODO: should exam the input
    num = stol(tmpStr.c_str());
    if(num<=0 || num>5000){
        cout<<"should input positive number or no more than 5000$"<<endl;
        return 0;
    }
    this->donate(num);
    cout<<endl<<"donate succeeded! "<<endl;
    this->view();
    return 0;

}

int Donor::donate(float addNum){
    if(this->amountDonated + addNum > 5000){
        cout<<"sorry, your current donate amount is "<<endl;
        this->total();
        cout<<"you can't donate more than 5000 "<<endl;
        return 1;
    }
    this->amountDonated += addNum;
    cout<< "added $" << addNum <<endl;
    return 0;

}

/**
 * print out balance
 */
int Donor::total(){
    cout<<this->donorLastName<<' ';
    cout<< "$" ;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<this->amountDonated<<endl;
    return 0;

};

int Donor::setIDandPasswd(){
    string tmpStr;
    /**
     * userID
     * contains at least 5 characters but no more than 10,
     * containing only letters and digits
     */
    while(1){
	    cout<<endl<<"original is:"<<this->userID<<endl;
	    cout<<"please input your userID: ";
	    getline(cin, tmpStr);
	    if(tmpStr == ""){
		    cout<< "userID remains"<<endl;
		    break;
	    }
        else if(tmpStr.length() >= 10 || tmpStr.length() <= 5){
		    cout<<"length of userID should be more than 5 character and less than 10 character"<<endl;
		    continue;
	    }else if(isHaveSpecialChar(tmpStr.c_str())){
		    cout<< "userID should not contain special char"<<endl;
		    continue;
	    }
	    else{
		    this->userID = tmpStr;
		    break;

	    }

    }

    /**
     * password
     * contains at least 6 characters,
     * including at least one digit
     * and one character that is neither a letter nor a digit
     */
    int chances  = 3;
    while(1){
        string newPasswd;
        string newPasswd2;
        cout<<"welcome, please input your new password: ";
        cin>>newPasswd;
        cout<<"please input new password again: ";
        cin>>newPasswd2;
        if(newPasswd != newPasswd2){
            cout<<"2 new passwd didn't match!!"<<endl;
            cout<<"fail to set passwd, you have "<<chances<<" chances"<<endl;
            chances--;
        }else{
            this->password = newPasswd;
            cout<<"your passwd has been changed"<<endl;
            break;
        }
        if(chances == 0){
            cout<<"fail to set passwd, this coincidant will report."<<endl;
            break;
        }

    }
    return 0;
};

/**
 * donorLastName
 * donorFirstName
 * contains only letters
 */
int Donor::setDonorName(){
    string tmpStr;
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

    while(1){
	    cout<<endl<<"original is:"<<this->donorFirstName<<endl;
	    cout<<"please input your Firstname: ";
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
		    this->donorFirstName = tmpStr;
		    break;

	    }

    }

    return 0;

};

/**
 * age
 * must be at least 18
 */
int Donor::setAge(){
    string tmpStr;
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
    return 0;
};

/**
 * set Address
 */
int Donor::setAddress(){
    string tmpStr;
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
	    if(tmpStr == ""){
		    cout<< "street name remains"<<endl;
		    break;
	    }else if(tmpStr.length() >= 80 || tmpStr.length() <= 1){
		    cout<<"length of name should be more than 1 character and less than 80 character"<<endl;
		    continue;
	    }
	    else if(any_of(tmpStr.begin(), tmpStr.end(), ::isdigit)){
		    cout<< "name should not contain digit"<<endl;
		    continue;
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
	    if(tmpStr == ""){
		    cout<< "town name remains"<<endl;
		    break;
	    }else if(tmpStr.length() >= 80 || tmpStr.length() <= 1){
		    cout<<"length of name should be more than 1 character and less than 80 character"<<endl;
		    continue;
	    }
	    else if(any_of(tmpStr.begin(), tmpStr.end(), ::isdigit)){
		    cout<< "name should not contain digit"<<endl;
		    continue;
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
    while(1){
        cout<<endl<<"origional state is: "<<this->state<<endl;
        cout<<" 1.NY, 2.PA, 3.RI, 4.NH, 5.VT, 6.MA, 7.CT, 8.ME"<<endl;
        cout<<"please input: ";
	    getline(cin, tmpStr);
	    if(tmpStr == ""){
		    cout<< "state name remains"<<endl;
		    break;
	    }else if(tmpStr.length() != 2){
		    cout<<"length of state should be exactly 2"<<endl;
		    continue;
	    }
	    else if(any_of(tmpStr.begin(), tmpStr.end(), ::isdigit)){
		    cout<< "state should not contain digit"<<endl;
		    continue;
	    }
	    else{
		    this->state = strtoState(tmpStr);
		    break;

	    }

    }

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

    return 0;
};

/**
 * to add all new information,
 * if tags is set to 1, remove setter of userID and passwd
 */
int Donor::add(int tags){
    string tmpStr;
    this->setDonorName();
    this->setAge();
    if(tags == 0){
        this->setIDandPasswd();
    }
    this->setAddress();
    /**
     * amountDonated
     * float, non-negative, total amount donated must not grow beyond $5,000
     */
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
    this->add(1);
    return 0;
}

float Donor::getAmountDonated(){
    return this->amountDonated;
}

//TODO: handle wrong cmd for no reason
int Donor::donorMain(){
    string cmd;
    while(1){
        cout<<endl;
        cout<<"this is donorMain"<<endl;
        cout<<"1.Add 2.Manage 3.View 4.Donate 5.Total 6.Logout"<<endl;
        cout<<"please input command:";
        getline(cin, cmd);
        if(cmd == "Add" || cmd=="add")
           this->add();
        else if(cmd == "Manage" || cmd=="manage")
            this->manage();
        else if(cmd == "View" || cmd=="view")
            this->view();
        else if(cmd == "Donate" || cmd=="donate")
            this->donate();
        else if(cmd == "Total" || cmd=="total")
            this->total();
        else if(cmd == "Quit" || cmd=="quit"){
            cout<< "good bye"<<endl;
            break;
        }else if(cmd == "Logout" || cmd=="logout"){
            this->logout();
            break;
        }else{
            cout<<endl<<"wrong cmd: "<<cmd<<endl;
        }

    }

    return 0;
};

int Donor::logout(){
    cout<< "good bye"<<endl;
    return 0;
};

string Donor::getUserID(){
    return this->userID;

};

string Donor::getPassword(){
    return this->password;
};

string Donor::getAlltoLine(){
    string line;
    line.append(this->donorFirstName);
    line.append(" ");
    line.append(this->donorLastName);
    line.append(" ");
    line.append(this->userID);
    line.append(" ");
    line.append(this->password);
    line.append(" ");
    line.append(to_string(this->age));
    line.append(" ");
    line.append(to_string(this->streetNumber));
    line.append(" ");
    line.append(this->streetName );
    line.append(" ");
    line.append(this->town );
    line.append(" ");
    line.append(to_string(this->state));
    line.append(" ");
    line.append(this->zipCode );
    line.append(" ");
    line.append(to_string(this->amountDonated));
    return line;
};
