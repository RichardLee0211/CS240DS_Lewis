#ifndef FBLCOMMENT_H
#define FBLCOMMENT_H

#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

class FBLComment{
    private:
        /* private data members */
        string strContent;
        string strCommenterLastName;
        string strCommenterFirstName;
        // TODO: ??
        // FBLUser* pFBLUserCommenter;
        // FBLUser doesn't name a type
        // In file included
        // from FBLPost.h:9:0,
        // from FBLPostLL.h:8,
        // from FBLUser.h:9,
        // from FBLUserLL.h:7,
        // from main.cpp:6:
        // FBLComment.h:16:9: error: ‘FBLUser’ does not name a type
        // FBLUser *pFBLUserCommenter;
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
