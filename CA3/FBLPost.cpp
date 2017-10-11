#include<iostream>

#include"FBLPost.h"
#include"FBLCommentLL.h"

using namespace std;

/*
FBLPost::FBLPost(){
    this->likes = 0;
    this->content = "defaultContant";
    this->commentLL = new FBLCommentLL();
    this->next = NULL;
    this->pre = NULL;
};
*/

FBLPost::FBLPost(string content){
    this->likes = 0;
    //TODO: ?? use tring copy function ??
    this->content = content;

    this->commentLL = new FBLCommentLL();
    this->next = NULL;
    this->pre = NULL;
};

int FBLPost::view(){
    cout<<this->content<<" likes: "<<this-likes<<endl;
    return 0;
}
