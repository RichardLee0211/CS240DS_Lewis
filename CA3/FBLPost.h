#ifndef FBLPOST_H
#define FBLPOST_H

#include<iostream>
#include<stdlib.h>
#include<string>

#include"FBLCommentLL.h"
#include"FBLComment.h"

using namespace std;

class FBLPost{
    private:
        int likes;
        string content;
        FBLCommentLL *commentLL;

    public:
        FBLPost* next;
        FBLPost* pre;
        //FBLPost();
        FBLPost(string text="defaultContent");

    public:
        int view();


};
#endif
