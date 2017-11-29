#include<iostream>
#include<vector>
#include<climits>
#include<list>

#include"FBLUser.h"
#include"util.h"

#include"FBLUserLL.h"

FBLUser::FBLUser(){
    this->lastName = "defaultLastName";
    this->firstName = "defaultFirstName";
    this->userID = "defaultUserID";
    this->passwd = "abcd";
    this->postLL = new FBLPostLL();

    this->next = NULL;
    this->prev = NULL;
    this->plistMyFeed = new list<FBLPost*>;
    return;
};

/**
 * value constructor
 * for CREATE <Userid> <Password> <First> <Last>
 */
FBLUser::FBLUser(string userID, string passwd, string firstName, string lastName){
    this->lastName = lastName;
    this->firstName = firstName;
    this->userID = userID;
    this->passwd = passwd;
    this->postLL = new FBLPostLL();

    this->next = NULL;
    this->prev = NULL;
    this->plistMyFeed = new list<FBLPost*>;
    return;
};

FBLUser::~FBLUser(){
    delete this->plistMyFeed;
    this->postLL->clearMem();
    delete this->postLL;
    return;
};

/**
 * POST
 */
int FBLUser::post(){
    string text;
    cout<<"input your text: ";
    cin>>text;
    if(!text.empty()){
        this->post(text);
    }
    return 0;
};

/**
 * POST <text>
 */
int FBLUser::post(string text){
    //TODO: check text for invalid input
    this->postLL->create(text);
    for(FBLUser* ptrFriend : this->vecFriends){
        ptrFriend->plistMyFeed->push_back(this->postLL->getHead());
        //ptrFriend->myFeed.push_back(text);
    }
    return 0;
}

/**
 * read first post and remove it
 * if list is empty, return -1
 * if it's -1, print Nothing to READ
 * TODO: for better design, maybe I should keep input and output in main
 * and reset this to return string
 */
int FBLUser::readandRemovePost(){
    if(this->postLL->empty())
        return -1;
    else{
        this->postLL->read();
    }
    return 0;
};

int FBLUser::logout(){
    return 0;
};

int FBLUser::mainLoop(){
    while(1){
        string strCmd;
        vector<string> vectCmd;
        cout<<endl;
        cout<<"welcome, "<<this->getUserID()<<endl;
        cout<<"$post $readPost $view"<<endl;
        cout<<"$friend $myfeed $readFeed $mywall"<<endl;
        cout<<"$logout"<<endl;
        cout<<"please input command:";
        getline(cin, strCmd);
#if DEBUG
        cout<<endl;
        cout<<"cmd from test: "<<strCmd<<endl;
        cout<<endl;
#endif
        splitString(strCmd, vectCmd, " ");
        if(vectCmd.empty()){
            cout<<"wrong cmd: empty cmd"<<endl;
#if DEBUG
            cout<<"ctrl-c to exit"<<endl;
            while(1); // TODO: which one could replace this stupid function.
#endif
        }
        else if(vectCmd[0]=="view" ||
                vectCmd[0]=="View" ||
                vectCmd[0]=="VIEW"){
            this->printUser();
        }
        else if(vectCmd[0]=="friend" ||
                vectCmd[0]=="Friend" ||
                vectCmd[0]=="FRIEND"){
            if(vectCmd.size() == 2){
                this->addFriend(vectCmd[1]);
            }else{
                this->addFriend();
            }
        }
        else if(vectCmd[0]=="myfriends" ||
                vectCmd[0]=="MyFriends" ||
                vectCmd[0]=="MYFRIENDS"){
                this->myfriends();
        }
        else if(vectCmd[0]=="post" ||
                vectCmd[0]=="Post" ||
                vectCmd[0]=="POST"){
            if(vectCmd.size() >= 2){
                string post = strCmd.substr(5);
                post += " from ";
                post += this->userID;
                this->post(post);
                //this->post(vectCmd[1]);
            }else{
                this->post();
            }
        }
        else if(vectCmd[0]=="readPost" ||
                vectCmd[0]=="ReadPost" ||
                vectCmd[0]=="READPOST"){
            if(this->readandRemovePost() == -1)
                cout<<"nothing to read"<<endl;
        }
        else if(vectCmd[0]=="mywall" ||
                vectCmd[0]=="Mywall" ||
                vectCmd[0]=="MYWALL"){
            this->postLL->view();
        }
        else if(vectCmd[0]=="myfeed" ||
                vectCmd[0]=="Myfeed" ||
                vectCmd[0]=="MYFEED"){
            this->readMyFeeds();
        }
        else if(vectCmd[0]=="read" ||
                vectCmd[0]=="Read" ||
                vectCmd[0]=="READ" ||
                vectCmd[0]=="readFeed" ||
                vectCmd[0]=="ReadFeed" ||
                vectCmd[0]=="READREED"){
            this->readandRemoveFeed();
        }
        else if(vectCmd[0]=="help" ||
                vectCmd[0]=="h" ||
                vectCmd[0]=="HELP" ||
                vectCmd[0]=="Help"){
            cout<<"## post: POST <text>"<<endl;
            cout<<"## readPost: read and remove a post"<<endl;
            cout<<"## view: view info of user"<<endl;
            cout<<"## friend: friend <userid>"<<endl;
            cout<<"## myfriend: print out friends' name"<<endl;
            cout<<"## myfeed: print out feed post"<<endl;
            cout<<"## readFeed: read and remove a Feed, or brief call read"<<endl;
            cout<<"## mywall: print out my posts"<<endl;
            cout<<"## logout: log out"<<endl;
        }
        else if(vectCmd[0]=="quit" ||
                vectCmd[0]=="Quit" ||
                vectCmd[0]=="QUIT"){
            this->quit();
            cout<< "good bye"<<endl;
            break;
        }
        else if(vectCmd[0]=="logout" ||
                vectCmd[0]=="Logout" ||
                vectCmd[0]=="LOGOUT"){
            this->logout();
            cout<< "good bye"<<this->getUserID()<<endl;
            break;
        }
        else{
            cout<<endl<<"wrong cmd: "<<strCmd<<endl;
        }
    }

    return 0;
};

int FBLUser::printUser(){
    cout<<this->lastName<<", ";
    cout<<this->firstName<<" ";
    cout<<"<"<<this->userID<<">\n";
    return 0;
};

int FBLUser::quit(){
    return 0;
}

int FBLUser::readPosts(){
    this->postLL->view();
    return 0;
}

int FBLUser::myWall(){
    this->postLL->view();
    return 0;
};

int FBLUser::readMyFeeds(){
    //if(this->myFeed->empty()){
    if(this->plistMyFeed->empty()){
        cout<<"empty feed"<<endl;
        return 0;
    }
    //for(string tmp : this->myFeed){
    for(FBLPost* tmp : *(this->plistMyFeed)){
        cout<<*tmp<<endl;
    }
    cout<<endl;
    return 0;
};

int FBLUser::readandRemoveFeed(){
    if(this->plistMyFeed->empty()){
        cout<<"empty feed"<<endl;
        return 0;
    }
    FBLPost* pPost = this->plistMyFeed->front();
    cout<<*pPost<<endl;
    pPost->mainloop(this->getFirstName(), this->getLastName());
    this->plistMyFeed->pop_front();
    return 0;
}


int FBLUser::isCorrectPasswd(string passwd){
    if(this->passwd == passwd)
        return 1;
    return 0;
};

/**
 * when User A friends UserB, then UserB automatically friends UserA
 */
int FBLUser::addFriend(string userID){
    //TODO: check userID
    FBLUser* tmp = userLL->getPointer(userID);
    if(tmp != NULL){
        this->vecFriends.push_back(tmp);
        tmp->vecFriends.push_back(this);
        return 0;
    }
    else{
        cout<<"failed to find "<<userID<<endl;
        return -1;
    }
}

int FBLUser::addFriend(){
    string tmp;
    cout<<"please input friend's userID: ";
    cin>>tmp;
    this->addFriend(tmp);
    return 0;
}

int FBLUser::myfriends(){
    if(this->vecFriends.empty()){
        cout<<"there is no friends on list"<<endl;
        return 0;
    }
    for(FBLUser* ptrFriend : this->vecFriends){
        cout<<ptrFriend->getFirstName()<<" "<<ptrFriend->getFirstName()<<endl;
    }
    cout<<endl;
    return 0;
};

string FBLUser::getLastName() const{
    return this->lastName;
}

string FBLUser::getFirstName() const{
    return this->firstName;
}

string FBLUser::getUserID() const{
    return this->userID;
}

/* global functions related to FBLUser */
bool operator< (const FBLUser& lhs, const FBLUser& rhs){
    return lhs.getLastName() < rhs.getLastName();
};
bool operator> (const FBLUser& lhs, const FBLUser& rhs){
    return rhs<lhs;
};
bool operator<=(const FBLUser& lhs, const FBLUser& rhs){
    return !(lhs>rhs);
};
bool operator>=(const FBLUser& lhs, const FBLUser& rhs){
    return !(lhs<rhs);
};

int swap(FBLUser* a, FBLUser* b){
    if(a == NULL || b == NULL)
        return -1;
    /* if a is next to b */
    if(b->next == a){
        FBLUser* tmp = a;
        a = b;
        b = tmp;
    }
    /* if b is next to a */
    if(a->next == b){
        FBLUser* aprev = a->prev;
        FBLUser* bnext = b->next;
        a->prev = b;
        a->next = bnext;
        b->prev = aprev;
        b->next = a;
        if(aprev != NULL)
            aprev->next = b;
        if(bnext != NULL)
            bnext->prev = a;
    }
    /* if a and b is not neighbor */
    else{
        FBLUser* aprev = a->prev;
        FBLUser* anext = a->next;
        FBLUser* bnext = b->next;
        FBLUser* bprev = b->prev;
        a->prev = bprev;
        a->next = bnext;
        b->prev = aprev;
        b->next = anext;
        if(aprev != NULL)
            aprev->next = b;
        if(anext != NULL)
            anext->prev = b;
        if(bprev != NULL)
            bprev->next = a;
        if(bnext != NULL)
            bnext->prev = a;
    }
    return 0;
};
