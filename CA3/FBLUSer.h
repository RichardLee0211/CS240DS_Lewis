#ifndef FBLUSER_H
#define FBLUSER_H

#include<iostream>
#include<stdlib.h>

#include"FBLPostLL.h"

class FBLUser{
    private:
        string lastName;
        string firstName;
        string userID;
        string passwd;
        FBLPostLL *postLL;

    public:
        // still think it's ugly,
        // user contains pointers to others, even they have little connections
        // TODO: what if these fields only public to FBLUserLL ??
        FBLUser* next;
        FBLUser* prev;

    public:
        FBLUser();

    public:
        int post();
        int read();
        int logout();
        int mainLoop();
};

#endif
