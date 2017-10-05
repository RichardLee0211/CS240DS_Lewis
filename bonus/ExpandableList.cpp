#include<iostream>

#include"ExpandableList.h"

using namespace std;

ExpandableList::ExpandableList(){
    this->listSize = 10;
    this->list = new ElementType[this->listSize];
    this->listUsedSize = 0;
};


ExpandableList::ExpandableList(ExpandableList& mylist){
    this->listSize = mylist.listSize;
    this->listUsedSize = mylist.listUsedSize;
    this->list = new ElementType[listSize];
    for(int i=0; i<this->listUsedSize; i++){
        this->list[i] = mylist.list[i];
    }
};

ExpandableList::~ExpandableList(){
    delete this->list;
};

ExpandableList& ExpandableList::operator=(const ExpandableList& mylist){
    delete this->list;
    this->listSize = mylist.listSize;
    this->listUsedSize = mylist.listUsedSize;
    this->list = new ElementType[listSize];
    for(int i=0; i<this->listUsedSize; i++){
        this->list[i] = mylist.list[i];
    }
    return *this;
};

ostream& ExpandableList::operator<<(ostream& os, const ExpandableList& mylist){
    // write obj to stream
    //mylist.list[i]
    //os.wirte
    //TODO
    return os;
};

//TODO
//     std::istream& operator>>(std::istream& is, T& obj)
//     {
//         // read obj from stream
//             if( /* T could not be constructed */ )
//                     is.setstate(std::ios::failbit);
//                         return is;
//                         }

int ExpandableList::add(ElementType addEle){
    if(this->listUsedSize == this->listSize){
        this->doubleListSize();
    }
    this->list[this->listUsedSize] = addEle;
    this->listUsedSize++;
    return 0;
};

int ExpandableList::doubleListSize(){
    this->listSize *= 2;
    ElementType* old = this->list;
    this->list = new ElementType[this->listSize];
    for(int i=0; i<this->listSize/2; i++)
        this->list[i] = old[i];
    delete old;

    return 0;
};

int ExpandableList::printAll(){
    for(int i=0; i<this->listUsedSize; i++){
        cout<<this->list[i]<<" ";
    }
    cout<<endl;
    return 0;
};
