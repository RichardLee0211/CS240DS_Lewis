#include<iostream>

#include"FBLComment.h"
// TODO: ??
// In file included from FBLComment.cpp:4:0:
// util.h:6:45: error: ¡®std::vector¡¯ has not been declared
// void splitString(const std::string& s, std::vector<std::string>& v, const std::string& c);
// util.h:6:51: error: expected ¡®,¡¯ or ¡®...¡¯ before ¡®<¡¯ token
// void splitString(const std::string& s, std::vector<std::string>& v, const std::string& c);
// #include"util.h"

using namespace std;

FBLComment::FBLComment(string content){
    this->strContent = content;
    return;
};

FBLComment::~FBLComment(){
    return;
};

int FBLComment::setCommenterLastName(string lastname){
    this->strCommenterLastName = lastname;
    return 0;
};
int FBLComment::setCommenterFirstName(string firstname){
    this->strCommenterFirstName = firstname;
    return 0;
};

ostream &operator<<(ostream &os, const FBLComment& comment){
    os<<comment.strContent<<" from: "<<comment.strCommenterFirstName<<" "
        <<comment.strCommenterLastName;
    return os;
};
