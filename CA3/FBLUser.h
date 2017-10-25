#ifndef FBLUSER_H
#define FBLUSER_H

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<list>

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

        //TODO: ??report corrupted double-linked list when try list<string> myFeed
        list<string> *plistMyFeed;

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
        ~FBLUser();
        FBLUser(string userID, string passwd, string firstName, string lastname);
        int printUser();
        string getUserID();
        string getLastName();
        string getFirstName();
        int quit();
        int addFriend(string userID);
        int addFriend();
        int isCorrectPasswd(string passwd);
        int myfriends();
        int readMyFeeds();
        int readPosts();
        int myWall();

    public:
        int post();
        int post(string text);
        int readandRemovePost();
        int readandRemoveFeed();
        int logout();
        int mainLoop();
};

#endif
