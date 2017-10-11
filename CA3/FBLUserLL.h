#ifndef FBLUSERLL_H
#define FBLUSERLL_H

#include<iostream>
#include<stdlib.h>

#include"FBLUser.h"

class FBLUserLL{
    private:
        FBLUser* head;
        FBLUser* end;
        FBLUser* curr;
        uint number;
    public:
        FBLUserLL();
        int printLL();

    public:
        int create();
        int create(string userID, string passwd, string firstName, string lastName);
        int login();
        int login(string userID);
        int quit();
        int mainLoop();
};
#endif
