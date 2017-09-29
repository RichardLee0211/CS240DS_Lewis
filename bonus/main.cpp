#include<iostream>

#include"ExpandableList.h"

using namespace std;

int main(){
    ExpandableList mylist;
    for(int i=0; i<14; i++){
        mylist.add(i);
        mylist.printAll();

    }


    return 0;

}
