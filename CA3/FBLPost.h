#ifndef FBLPOST_H
#define FBLPOST_H

#include<iostream>
#include<stdlib.h>
#include<string>
#include<list>

#include"FBLComment.h"

using namespace std;

class FBLPost{
    private:
        /* private members */
        int likes;
        string content;
        // list<FBLComment*> commentLL;
        list<FBLComment*> *plistCommentLL;

    public:
        FBLPost* next;
        FBLPost* prev;

    public:
        /* basical functions */
        //FBLPost();
        FBLPost(string text="defaultContent");
        ~FBLPost();

    public:
        int view();
        // TODO: the same problem here, can't use #include"FLBUser.h"
        // int mainloop(FBLUser* pUser);
        int mainloop(string strFirstName, string strLastName);
        int like();
        int comment(string content, string strCommenterFirstName, string strCommenterLastName);
        int comment(string strCommenterFirstName, string strCommenterLastName);
        int read_az();
        int read_za();
        int done();

        /* friend functions */
        friend ostream &operator<<(ostream &os, const FBLPost& post);

};

/* some compilers require seperate declare of friend function */
ostream &operator<<(ostream &os, const FBLPost& post);

#endif
