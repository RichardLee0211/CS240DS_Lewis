#include<iostream>

#include"FBLPostLL.h"
#include"FBLPost.h"

FBLPostLL::FBLPostLL(){
    this->head = NULL;
    this->end = NULL;
    this->curr = NULL;
    this->number = 0;
};

// ?? never called when delete this->postLL in user class??
FBLPostLL::~FBLPostLL(){
    /*
    FBLPost* tmp = this->head;
    while(tmp != NULL){
        this->curr = tmp->next;
        delete tmp;
        tmp = this->curr;
    }
    return;
    */
};

int FBLPostLL::clearMem(){
    FBLPost* tmp = this->head;
    while(tmp != NULL){
        this->curr = tmp->next;
        delete tmp;
        tmp = this->curr;
    }
    return 0;
};

/*
int FBLPostLL::create(){
    //TODO: it have similar code of FBLPostLL::create(string)
    if(this->number == 0){
        this->head = new FBLPost();
        this->head->next = NULL;
        this->head->pre = NULL;
        this->end = this->head;
        this->curr = this->head;
    }else{
        this->end->next = new FBLPost();
        this->end->next->pre = this->end;
        this->end = this->end->next;
    }
        this->number++;
    return 0;
};
*/

int FBLPostLL::create(string text){
    // TODO: check argument
    if(this->number == 0){
        this->head = new FBLPost(text);
        this->head->next = NULL;
        this->head->prev = NULL;
        this->end = this->head;
        this->curr = this->head;
    }
#if 0
    // insert to the end
    else{
        this->end->next = new FBLPost(text);
        this->end->next->pre = this->end;
        this->end = this->end->next;
    }
#endif
    // insert to the head
    else{
        this->head->prev = new FBLPost(text);
        this->head->prev->next = this->head;
        this->head = this->head->prev;
    }
        this->number++;
    return 0;
}

/**
 * display the first FBLPost in the currently logged user’s postings (for now)
 * and remove it from that list.
 */
int FBLPostLL::read(){
    FBLPost *tmp = this->head;
    if(tmp != NULL){
        tmp->view();
    }
    this->removeHead();
    return 0;
};

/**
 * remove head
 * if List is empty, return -1
 */
int FBLPostLL::removeHead(){
    if(this->empty())
        return -1;
    FBLPost *tmp = this->head->next;
    delete this->head;
    this->head = tmp;;
    if(this->head != NULL)
        this->head->prev = NULL;
    this->number--;
    return 0;

};

/**
 * is it empty
 */
int FBLPostLL::empty(){
    if(this->number == 0)
        return 1;
    else
        return 0;
};

/**
 * just print out all posting
 */
int FBLPostLL::view(){
    FBLPost *tmp = this->head;
    while(tmp != NULL){
        tmp->view();
        tmp = tmp->next;
    }
    cout<<"end of Posts"<<endl;
    return 0;
};

FBLPost* FBLPostLL::getHead(){
    return this->head;
};

/* friend function of class FBLPostLL */
ostream &operator<<(ostream &os, const FBLPostLL& postLL){
    FBLPost *tmp = postLL.head;
    while(tmp != NULL){
        os<<*tmp<<endl;
        tmp = tmp->next;
    }
    os<<"end of Posts"<<endl;
    return os;
};
