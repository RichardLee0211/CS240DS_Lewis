#include<iostream>
#include<stdlib.h>

#include"Donor.h"
#include"Exchange.h"

using namespace std;

int main(){

    Donor* myDonor = new Donor();
    string cmd;
    myDonor->add();
    while(1){
        cout<<endl<<"1.add 2.manage 3.view 4.donate 5.total 6.quit"<<endl;
        cout<<"please input command:";
        cin>>cmd;
        if(cmd == "add")
            myDonor->add();
        else if(cmd == "manage")
            myDonor->manage();
        else if(cmd == "view")
            myDonor->view();
        else if(cmd == "donate"){
            cout<< "please input $: ";
            int num;
            cin>>num;
            myDonor->donate(num);
            cout<<endl<<"donate succeeded! "<<endl;
            myDonor->view();

        }
        else if(cmd == "total")
            myDonor->total();

        else if(cmd == "quit"){
            cout<< "good bye"<<endl;
            break;

        }
        else{
            cout<<endl<<"wrong cmd: "<<cmd<<endl;

        }


    }

    return 0;

}
