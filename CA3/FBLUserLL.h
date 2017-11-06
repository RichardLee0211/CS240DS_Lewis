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
        ~FBLUserLL();
        int printLL();

    public:
        //int create();
        int create(
                string userID="defaultUserID",
                string passwd="defaultPasswd",
                string firstName="defaultFirstName",
                string lastName="defaultLastName");
        int login();
        int login(string userID);
        int login(string userID, string passwd);
        int quit();
        int mainLoop();

        // friend FBLUser* getPointer(string userID);
        FBLUser* getPointer(string userID);
        int sortUsers();
};
#endif
