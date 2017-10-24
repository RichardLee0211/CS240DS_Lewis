#include<iostream>
#include<vector>
#include<climits>
#include<list>

#include"FBLUser.h"
#include"util.h"

// TODO: to find a better design,
// maybe I shouldn't put mainloop as member functions of FBLUser and FBLUserLL
// but this do need info from FBLUserLL
#include"FBLUserLL.h"

FBLUser::FBLUser(){
    this->lastName = "defaultLastName";
    this->firstName = "defaultFirstName";
    this->userID = "defaultUserID";
    this->passwd = "abcd";
    this->postLL = new FBLPostLL();

    this->next = NULL;
    this->prev = NULL;
    this->plistMyFeed = new list<string>;
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
    this->plistMyFeed = new list<string>;
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
        ptrFriend->plistMyFeed->push_back(text);
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
        else if(vectCmd[0]=="myfriend" ||
                vectCmd[0]=="MyFriend" ||
                vectCmd[0]=="MYFRIEND"){
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
    cout<<this->lastName<<"\t";
    cout<<this->firstName<<endl;
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
    for(string tmp : *(this->plistMyFeed)){
    //for(string tmp : this->myFeed){
        cout<<tmp<<endl;
    }
    cout<<endl;
    return 0;
};

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

int FBLUser::readandRemoveFeed(){
    cout<<this->plistMyFeed->front()<<endl;
    this->plistMyFeed->pop_front();
    return 0;
}

string FBLUser::getLastName(){
    return this->lastName;
}

string FBLUser::getFirstName(){
    return this->firstName;
}

string FBLUser::getUserID(){
    return this->userID;
}
