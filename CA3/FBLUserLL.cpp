#include<iostream>

#include"FBLUserLL.h"
#include"FBLUser.h"

FBLUserLL::FBLUserLL(){
    this->head = NULL;
    this->end = NULL;
    this->curr = NULL;
    this->number = 0;
};

int FBLUserLL::create(){
    if(this->number==0){
        this->head = new FBLUser();
        this->end = this->head;
        this->curr = this->head;
        this->head->prev = NULL;
        this->end->next = NULL;
    }else{
        this->end->next = new FBLUser();
        this->end->next->prev = this->end;
        this->end=this->end->next;
        this->end->next = NULL;
    }
    this->number++;
    return 0;

};

int FBLUserLL::login(){
    this->curr->mainLoop();
    return 0;
};

int FBLUserLL::quit(){};

int FBLUserLL::mainLoop(){};
