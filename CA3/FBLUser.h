#ifndef FBLUSER_H
#define FBLUSER_H

#include<iostream>
#include<stdlib.h>
#include<vector>

#include"FBLPostLL.h"

using namespace std;

class FBLUser{
    private:
        string lastName;
        string firstName;
        string userID;
        string passwd;
        FBLPostLL *postLL;
        vector<FBLUser*> vecFriends;

    public:
        // still think it's ugly,
        // user contains pointers to others, even they have little connections
        // usually, we store user in Database, using unique userID
        // but not linked list
        // TODO: what if these fields only public to FBLUserLL ??
        FBLUser* next;
        FBLUser* prev;

    public:
        FBLUser();
        FBLUser(string userID, string passwd, string firstName, string lastname);
        int printUser();
        string getUserID();
        int quit();
        int readPosts();
        int addFriend(string userID);

    public:
        int post();
        int post(string text);
        int read();
        int logout();
        int mainLoop();
};

#endif
