#ifndef FBLCOMMENT_H
#define FBLCOMMENT_H

#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

class FBLUser;

class FBLComment{
    private:
        /* private data members */
        string strContent;
        string strCommenterLastName;
        string strCommenterFirstName;
        // FBLUser* pCommenter;
    public:
        /* basical class functions */
        FBLComment(string content);
        ~FBLComment();

    public:
        /* other functions */
        int setCommenterLastName(string lastname);
        int setCommenterFirstName(string firstname);

        /* friend function */
        friend ostream &operator<<(ostream &os, const FBLComment& comment);

};

// TODO: does it need to be friend function?
ostream &operator<<(ostream &os, const FBLComment& comment);

#endif
