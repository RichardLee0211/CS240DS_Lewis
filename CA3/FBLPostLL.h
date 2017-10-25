#ifndef FBLPOSTLL_H
#define FBLPOSTLL_H

#include<iostream>
#include<stdlib.h>
#include<string>

#include"FBLPost.h"

class FBLPostLL{
    private:
        FBLPost *head;
        FBLPost *end;
        FBLPost *curr;
        uint number;

    public:
        FBLPostLL();
        ~FBLPostLL();
        int clearMem();
        int printLL();
        int removeHead();
        int empty();

    public:
        //int create();
        int create(string text="defaultText");
        int read();
        int view();

};
#endif
