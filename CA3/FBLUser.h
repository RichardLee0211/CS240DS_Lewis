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
        /* private data member */
        string lastName;
        string firstName;
        string userID;
        string passwd;
        FBLPostLL *postLL;
        vector<FBLUser*> vecFriends;

        // TODO: ??report corrupted double-linked list
        // when try list<string> myFeed
        // list<string> *plistMyFeed;
        list<FBLPost*> *plistMyFeed;

    public:
        /* next and prev */
        // still think it's ugly,
        // user contains pointers to others, even they have little connections
        // usually, we store user in Database, using unique userID
        // but not linked list
        // TODO: what if these fields only public to FBLUserLL ??
        // use friend
        FBLUser* next;
        FBLUser* prev;

    public:
        /* basical function of a class */
        FBLUser();
        FBLUser(string userID, string passwd, string firstName, string lastname);
        ~FBLUser();

    public:
        /* getters and setters */
        string getUserID() const;
        string getLastName() const;
        string getFirstName() const;

    public:
        /* functions */
        int printUser();
        int quit();
        int addFriend(string userID);
        int addFriend();
        int isCorrectPasswd(string passwd);
        int myfriends();
        int readMyFeeds();
        int readPosts();
        int myWall();
        int post();
        int post(string text);
        int readandRemovePost();
        int readandRemoveFeed();
        int logout();
        int mainLoop();

};

bool operator< (const FBLUser& lhs, const FBLUser& rhs);
bool operator> (const FBLUser& lhs, const FBLUser& rhs);
bool operator<=(const FBLUser& lhs, const FBLUser& rhs);
bool operator>=(const FBLUser& lhs, const FBLUser& rhs);
int swap(FBLUser* a, FBLUser* b);

#endif
