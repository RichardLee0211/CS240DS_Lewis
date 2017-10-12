#include<iostream>
#include<vector>

#include"FBLUser.h"
#include"util.h"

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
    //TODO: exam text
    this->postLL->create();
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
        cout<<"this is User interface"<<endl;
        cout<<"welcome, "<<this->getUserID()<<endl;
        cout<<"1.read 2.post 3.view 4.logout"<<endl;
        cout<<"POST <text>"<<endl;
#if DEBUG
        cout<<"5. readPosts"<<endl;

#endif
        cout<<"please input command:";
        getline(cin, strCmd);
        //TODO: ?? how to use test_input to test
        //keep loop
        cin.ignore(INT_MAX, '\n');
        splitString(strCmd, vectCmd, " ");
        if(vectCmd.empty()){
            cout<<"empty cmd"<<endl;
            continue;
        }
        else if(     vectCmd[0]=="read" ||
                vectCmd[0]=="Read" ||
                vectCmd[0]=="READ"){
            if(vectCmd.size() == 5){
            }else{
                this->read();
            }
        }
        else if(vectCmd[0]=="view" ||
                vectCmd[0]=="View" ||
                vectCmd[0]=="VIEW"){
            this->printUser();
        }
        else if(vectCmd[0]=="logout" ||
                vectCmd[0]=="Logout" ||
                vectCmd[0]=="LOGOUT"){
            this->logout();
            cout<< "good bye"<<this->getUserID()<<endl;
            break;
        }
        else if(vectCmd[0]=="post" ||
                vectCmd[0]=="Post" ||
                vectCmd[0]=="POST"){
            if(vectCmd.size() == 2){
                this->post(vectCmd[1]);
            }else{
                this->post();
            }
            break;
        }
#if DEBUG
        else if(vectCmd[0]=="readPosts" ||
                vectCmd[0]=="ReadPosts" ||
                vectCmd[0]=="READPOSTS"){
            this->postLL->view();
        }
#endif
        else if(vectCmd[0]=="quit" ||
                vectCmd[0]=="Quit" ||
                vectCmd[0]=="QUIT"){
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
