#include<iostream>
#include<vector>

#include"FBLPost.h"
#include"util.h"
#include"FBLUser.h"

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
    this->content = content;

    // this->commentLL // this member doesn't need initial;
    this->plistCommentLL = new list<FBLComment*>;

    this->next = NULL;
    this->prev = NULL;
    return;
};

FBLPost::~FBLPost(){
    /* release memory of comment */
    for(auto iter: *this->plistCommentLL){
        delete iter;
    }
    /* release commentLL itself */
    delete this->plistCommentLL;
    return;
};

int FBLPost::view(){
    cout<<this->content<<" likes: "<<this->likes<<endl;
    return 0;
};

int FBLPost::like(){
    this->likes++;
    return 0;
};

int FBLPost::comment(string strCommenterFirstName, string strCommenterLastName){
    string content;
    cout<<"please input your commment: ";
    cin>>content;
    this->comment(content, strCommenterFirstName, strCommenterFirstName);
    return 0;
};

int FBLPost::comment(string content, string strCommenterFirstName, string strCommenterLastName){
    FBLComment* pComment = new FBLComment(content);
    this->plistCommentLL->push_front(pComment);
    pComment->setCommenterLastName(strCommenterFirstName);
    pComment->setCommenterFirstName(strCommenterLastName);
    return 0;
};

int FBLPost::read_az(){
    for(FBLComment* pComment : *(plistCommentLL)){
        cout<<*(pComment)<<endl;
    }
    return 0;
};

int FBLPost::read_za(){
    // TODO: since end() return a pointer pointing to NULL
    // and iter is a pointer to pointer, *iter is the pointer to object
    // so **iter is object, figure out what's a iterator
    auto iter=this->plistCommentLL->end();
    for(iter--;
            iter!=this->plistCommentLL->begin();
            iter--){
        cout<<**iter<<endl;
    }
    cout<<**iter<<endl;
    return 0;
};

int FBLPost::done(){
    return 0;
}

/* mainLoop */
// int FBLPost::mainloop(FBLUser* pUser){
int FBLPost::mainloop(string strFirstName, string strLastName){
    while(1){
        string strCmd;
        vector<string> vectCmd;
        cout<<endl;
        cout<<"this is post interface"<<endl;
        cout<<"$like $comment $read_az $read_za"<<endl;
        cout<<"$help"<<endl;
        cout<<"$done"<<endl;
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
            while(1);
#endif
        }
        else if(vectCmd[0]=="like" ||
                vectCmd[0]=="Like" ||
                vectCmd[0]=="LIKE"){
            this->like();
        }
        else if(vectCmd[0]=="comment" ||
                vectCmd[0]=="Comment" ||
                vectCmd[0]=="COMMENT"){
            if(vectCmd.size() >= 2){
                string comment = strCmd.substr(8);
                this->comment(comment, strFirstName, strLastName);
            }else{
                this->comment(strFirstName, strLastName);
            }
        }
        else if(vectCmd[0]=="read_az" ||
                vectCmd[0]=="Read_az" ||
                vectCmd[0]=="READ_AZ"){
            this->read_az();
        }
        else if(vectCmd[0]=="read_za" ||
                vectCmd[0]=="Read_za" ||
                vectCmd[0]=="READ_ZA"){
            this->read_za();
        }
        else if(vectCmd[0]=="help" ||
                vectCmd[0]=="Help" ||
                vectCmd[0]=="HELP" ||
                vectCmd[0]=="h"){
            cout<<"$like: LIKE increase like count by 1"<<endl;
            cout<<"$comment: COMMENT <text>"<<endl;
            cout<<"$read_az: print out info of postLL"<<endl;
            cout<<"$read_za: print out info of postLL in reverse order"<<endl;
            cout<<"$done: just quit"<<endl;
        }
        else if(vectCmd[0]=="done" ||
                vectCmd[0]=="Done" ||
                vectCmd[0]=="DONE"){
            this->done();
            cout<< "welcome back to like and comment"<<endl;
            break;
        }
        else{
            cout<<endl<<"wrong cmd: "<<strCmd<<endl;
        }
    }
    return 0;
};

/* friend functions of class FBLPost */
ostream &operator<<(ostream &os, const FBLPost& post){
    os<< post.content<<" likes: "<<post.likes;
    return os;
};
