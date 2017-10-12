#include<iostream>
#include<vector>

#include"FBLUserLL.h"
#include"FBLUser.h"
#include"util.h"

FBLUserLL::FBLUserLL(){
    this->head = NULL;
    this->end = NULL;
    this->curr = NULL;
    this->number = 0;
};

/**
 * deconstructor
 * TODO:
 */

/**
 * operate<<
 * TODO:
 */


/*
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
*/

/**
 * CREATE <Userid> <Password> <First> <Last>
 * check out if userid is duplicate
 */
int FBLUserLL::create(string userID, string passwd, string firstName, string lastName){
    //TODO: check inputs
    /**
     * check if userID is duplicate
     */
    FBLUser * tmp = this->head;
    while(tmp != NULL){
        if(tmp->getUserID() == userID){
            //TODO: how to do it with exception??
            return -1; //flag for duplicate
        }
        tmp = tmp->next;
    }

    if(this->number==0){
        this->head = new FBLUser(userID, passwd, firstName, lastName);
        this->end = this->head;
        this->curr = this->head;
        this->head->prev = NULL;
        this->end->next = NULL;
    }else{
        this->end->next = new FBLUser(userID, passwd, firstName, lastName);
        this->end->next->prev = this->end;
        this->end=this->end->next;
        this->end->next = NULL;
    }
    this->number++;
    return 0;

};

/**
 * LOGIN
 */
int FBLUserLL::login(){
    string userID;
    cout<<"please input your userID: ";
    cin>>userID;
    if(!userID.empty()){
        this->login(userID);
    }
    return 0;
};

/**
 * LOGIN <Userid>
 */
int FBLUserLL::login(string userID){
    //TODO: to exam the userID

    this->curr = this->head;
    while(this->curr != NULL){
        if(this->curr->getUserID() == userID){
            this->curr->mainLoop();
            break;
        }
        this->curr = this->curr->next;
    }
    return 1;
}

/**
 * LOGIN <userid> <passwd>
 * TODO:
 */

/**
 * QUIT
 */
int FBLUserLL::quit(){
    return 1;
};

int FBLUserLL::mainLoop(){
    while(1){
        string strCmd;
        vector<string> vectCmd;
        cout<<endl;
        cout<<"this is Top interface"<<endl;
        cout<<"1.create 2.login 3.view 4.quit"<<endl;
        cout<<"1. CREATE <Userid> <Password> <First> <Last>"<<endl;
        cout<<"2. LOGIN <userID>"<<endl;
        cout<<"please input command:";
        getline(cin, strCmd);
        //TODO: ?? how to use test_input to test
        //keep loop
        //cin.ignore(INT_MAX, '\n');
        cin.ignore(INT_MAX);
        //cin.clear();
        splitString(strCmd, vectCmd, " ");
        if(vectCmd.empty()){
            cout<<"empty cmd"<<endl;
            break;
        }
        else if(vectCmd[0]=="create" ||
                vectCmd[0]=="Create" || vectCmd[0]=="CREATE"){
            if(vectCmd.size() == 5){
                this->create(vectCmd[1], vectCmd[2], vectCmd[3], vectCmd[4]);
            }else{
                this->create();
            }
        }
        else if(vectCmd[0]=="login" ||
                vectCmd[0]=="Login" || vectCmd[0]=="LOGIN"){
            if(vectCmd.size() == 2){
                this->login(vectCmd[1]);
            }else{
                this->login();
            }
        }
        else if(vectCmd[0]=="view" ||
                vectCmd[0]=="View" || vectCmd[0]=="VIEW"){
            this->printLL();
        }
        else if(vectCmd[0]=="quit" ||
                vectCmd[0]=="Quit" || vectCmd[0]=="QUIT"){
            this->quit();
            cout<< "good bye"<<endl;
            break;
        }
        else{
            cout<<endl<<"wrong cmd: "<<strCmd<<endl;
        }
    }

    return 0;
};

int FBLUserLL::printLL(){
    FBLUser* tmp = this->head;
    while(tmp != NULL){
        tmp->printUser();
        tmp = tmp->next;
    }
    return 0;

};
