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
        if(cmd == "Login" || cmd=="login")
            database->login();
        else if(cmd == "Add" || cmd=="add")
            database->add();
        else if(cmd == "Save" || cmd=="save")
            database->save();
        else if(cmd == "Load" || cmd=="load")
            database->load();
        else if(cmd == "Report"|| cmd=="report")
            database->report();
        else if(cmd == "Quit" || cmd=="quit"){
            if(database->quit() != 0){
                cout<<"quit error"<<endl;
            }else{
                cout<< "good bye"<<endl;
                break;
            }
        }else{
            cout<<endl<<"wrong cmd: "<<cmd<<endl;
        }
    }




    return 0;
}
