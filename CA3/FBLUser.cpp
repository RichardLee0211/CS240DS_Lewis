#include<iostream>
#include<vector>
#include<climits>

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
    return 0;
}

/**
 * read first post and remove it
 * if list is empty, return -1
 * if it's -1, print Nothing to READ
 * TODO: for better design, maybe I should keep input and output in main
 * and reset this to return string
 */
int FBLUser::read(){
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
        cout<<"1.read 2.post 3.view "<<endl;
        cout<<"4.friend 5.myfeed 6.mywall"<<endl;
        cout<<"when finished, you can type \"logout \""<<endl;
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
        else if(vectCmd[0]=="post" ||
                vectCmd[0]=="Post" ||
                vectCmd[0]=="POST"){
            if(vectCmd.size() == 2){
                this->post(vectCmd[1]);
            }else{
                this->post();
            }
        }
        else if(vectCmd[0]=="read" ||
                vectCmd[0]=="Read" ||
                vectCmd[0]=="READ"){
            if(this->read() == -1)
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
            //TODO: may use std::list this time
            //this->postLL->view();
        }
        else if(vectCmd[0]=="help" ||
                vectCmd[0]=="h" ||
                vectCmd[0]=="HELP" ||
                vectCmd[0]=="Help"){
            cout<<"## read post"<<endl;
            cout<<"## POST <text>"<<endl;
            cout<<"## view info of user"<<endl;
            cout<<"## friend <userid>"<<endl;
            cout<<"## myfriend: print out friends' name"<<endl;
            cout<<"## myfeed: print out feed post"<<endl;
            cout<<"## mywall: print out my posts"<<endl;
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

string FBLUser::getUserID(){
    return this->userID;
}

int FBLUser::quit(){
    return 0;
}

int FBLUser::readPosts(){
    this->postLL->view();
    return 0;
}

int FBLUser::isCorrectPasswd(string passwd){
    if(this->passwd == passwd)
        return 1;
    return 0;
};

//TODO: how to get FBLUser pointer??
int FBLUser::addFriend(string userID){
    FBLUser* tmp = getPointer(userID);
    //this->vecFriends.push_back();
    return 0;
}
