#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<algorithm>

#include"Donor.h"
#include"DonorDatabase.h"
#include"util.h"

using namespace std;

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
        database->load(argv[2]);

    }

    string cmd;
    while(1){
        cout<<endl;
        cout<<"this is databaseMain"<<endl;
        cout<<"1.Login 2.Add 3.Save 4.Load 5.Report 6.Quit "<<endl;
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
