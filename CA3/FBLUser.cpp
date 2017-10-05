#include<iostream>

#include"FBLUser.h"

FBLUser::FBLUser(){
    this->lastName = "defaultLastName";
    this->firstName = "defaultFirstName";
    this->userID = "defaultUserID";
    this->passwd = "abcd";
    this->postLL = new FBLPostLL();

    this->next = NULL;
    this->prev = NULL;
};

int FBLUser::post(){
};

int FBLUser::read(){
};

int FBLUser::logout(){
};

int FBLUser::mainLoop(){};
