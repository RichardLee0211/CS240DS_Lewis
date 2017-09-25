#include<stdio.h>
#include<fstream>
#include<iostream>
#include<cstring>
#include<vector>

#include"Donor.h"
#include"DonorDatabase.h"

using namespace std;


DonorDatabase::DonorDatabase(){
    this->donors = new Donor[1000];
};

DonorDatabase::DonorDatabase(int donorsMax){
    this->donors = new Donor[donorsMax];
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
    //TODO
    return 0;
};

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c){
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}

int DonorDatabase::load(string filedir){
    ifstream ifs(filedir, ifs.binary | ifs.in );
    if(!ifs.is_open())
        cout<<"failed to open file"<<endl;

    string line;
    string delim = " ";
    std::vector<std::string> attri;

    while(!ifs.eof()){
        getline(ifs, line);
        cout<<line<<endl;
        SplitString(line, attri, delim);
        string firstname = attri[0];
        cout<<"firstname"<<firstname<<endl;
        //this->donors[0].setDonor
        attri.clear();

    }


    //TODO
    return 0;
};

int DonorDatabase::report(){
    //TODO
    return 0;
};

int DonorDatabase::quit(){
    //TODO
    return 0;
};
