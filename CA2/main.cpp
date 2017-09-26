#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<algorithm>

#include"Donor.h"
#include"DonorDatabase.h"
#include"util.h"

using namespace std;

int DonorMain(){
    Donor* myDonor = new Donor();
    string cmd;
    while(1){
        cout<<endl<<"1.add 2.manage 3.view 4.donate 5.total 6.quit"<<endl;
        cout<<"please input command:";
        getline(cin, cmd);
        if(cmd == "add")
            myDonor->add();
        else if(cmd == "manage")
            myDonor->manage();
        else if(cmd == "view")
            myDonor->view();
        else if(cmd == "donate")
            myDonor->donate();
        else if(cmd == "total")
            myDonor->total();
        else if(cmd == "quit"){
            cout<< "good bye"<<endl;
            break;
        }
        else{
            cout<<endl<<"wrong cmd: "<<cmd<<endl;
            break;
        }


    }

    return 0;
}

int main(int argc, char* argv[]){
    int donorsMax = 1;
    if(argc==1 || argc > 3) {
        printf("wrong arguments number\n");
        return 1;
    }

    donorsMax = atoi(argv[1]);
    if(donorsMax<1 || donorsMax>DONORS_MAX){
        printf("wrong donors number\n");
        return 1;
    }
    DonorDatabase* database = new DonorDatabase(donorsMax);

    if(argc==3){
        //TODO: read file into DonorData
    }

    string cmd;
    while(1){
        cout<<endl<<"1.Login 2.Add 3.Save 4.Load 5.Report 6.Quit "<<endl;
        cout<<"please input command:";
        getline(cin, cmd);
        if(cmd == "Login")
            database->login();
        else if(cmd == "Add")
            database->add();
        else if(cmd == "Save")
            database->save();
        else if(cmd == "Load")
            database->load();
        else if(cmd == "Report")
            database->report();
        else if(cmd == "Quit"){
            database->quit();
            cout<< "good bye"<<endl;
            break;
        }
        else{
            cout<<endl<<"wrong cmd: "<<cmd<<endl;
        }
    }




    return 0;
}
