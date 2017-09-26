#include<iostream>
#include<vector>

#include"Donor.h"
#include"DonorDatabase.h"

using namespace std;

#define DONORS_MAX 1000

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
};

enum State strtoState(string str){
    if(str == "NY") return NY;
    if(str == "PA") return PA;
    if(str == "RI") return RI;
    if(str == "NH") return NH;
    if(str == "VT") return VT;
    if(str == "MA") return MA;
    if(str == "CT") return CT;
    if(str == "ME") return ME;
    return NY;

};
