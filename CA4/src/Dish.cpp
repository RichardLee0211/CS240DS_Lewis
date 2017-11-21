#include<iostream>
#include<string>

#include"Dish.h"

class Comparator{
    public:
        static bool sortbylength(const std::string& elem1, const std::string elem2){
            if(sizeof(elem1) <= sizeof(elem2)) return true;
            else return false;
        };
        static bool sortbyalph(const std::string& elem1, const std::string elem2){
            if(elem1 <= elem2) return true;
            else return false;
        };
};

int Dish::insert(std::string s){
    // std::string* pstr = new std::string(s);
    this->list[this->number] = s;
    // insert &this->list[this->number] to heapLength
    // std::push_heap std::pop_heap
    return this->number++;
};

int Dish::find(std::string s){
    for(int i=0; i<number; ++i){
        if(this->list[i] == s)
            return i;
    }
    return -1;
};

bool Dish::capitalize(int k){
    k--; // hate kth string, but index is k-1, what a stupid API
    if(k >= this->number) return false;
    return true;
};

bool Dish::allcaps(int k){
    k--; // hate kth string, but index is k-1, what a stupid API
    if(k >= this->number) return false;
    return true;
};

bool Dish::truncate(int k, int i){
    k--; // hate kth string, but index is k-1, what a stupid API
    if(k >= this->number) return false;
    if(i >= sizeof(this->list[k])) return true;
    return true;
};

std::string Dish::getshortest(){
    std::string what;
    return what;
};

std::string Dish::getfirst(){
    std::string what;
    return what;
};
