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

    public:
        int create();
        int login();
        int quit();
        int mainLoop();
};
#endif
