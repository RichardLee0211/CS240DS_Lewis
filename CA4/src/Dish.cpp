#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>

#include"Dish.h"

#define IS_STD 1

#if !IS_STD
void make_heap(RandomIt begin, RandomIt end, Compare compare){
    return;
}
#endif


class Comparator{
    public:
        static bool sortbylength(const std::string* elem1, const std::string* elem2){
            // if(sizeof(*elem1) <= sizeof(*elem2)) return true;
            // sizeof(string) == 24 forever
            if(elem1->length() >= elem2->length()) return true;
            else return false;
        };
        static bool sortbyalph(const std::string* elem1, const std::string* elem2){
            if(*elem1 >= *elem2) return true;
            else return false;
        };
};

int Dish::insert(std::string s){
    if(this->number >= 1024 ) return -1;
    if(s.empty()) return -1;

    this->list[this->number] = s;

    this->heapLength.push_back(&this->list[this->number]);
#if IS_STD
    // std::push_heap(this->heapLength.begin(), this->heapLength.end(), Comparator::sortbylength);
    std::make_heap(this->heapLength.begin(), this->heapLength.end(), Comparator::sortbylength);
#else
    make_heap(this->heapLength.begin(), this->heapLength.end(), Comparator::sortbylength);
#endif

    this->heapAlph.push_back(&this->list[this->number]);
#if IS_STD
    // std::push_heap(this->heapAlph.begin(), this->heapAlph.end(), Comparator::sortbyalph);
    std::make_heap(this->heapAlph.begin(), this->heapAlph.end(), Comparator::sortbyalph);
#else
    make_heap(this->heapAlph.begin(), this->heapAlph.end(), Comparator::sortbyalph);
#endif

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
    if(k >= this->number || k<0) return false;

    this->list[k][0] = std::toupper(this->list[k][0]);

#if IS_STD
    std::make_heap(this->heapLength.begin(), this->heapLength.end(),
            Comparator::sortbylength); // TODO: ??
    std::make_heap(this->heapAlph.begin(), this->heapAlph.end(),
            Comparator::sortbyalph);
#else
    make_heap(this->heapLength.begin(), this->heapLength.end(),
            Comparator::sortbylength); // TODO: ??
    make_heap(this->heapAlph.begin(), this->heapAlph.end(),
            Comparator::sortbyalph);
#endif

    return true;
};

bool Dish::allcaps(int k){
    k--; // hate kth string, but index is k-1, what a stupid API
    if(k >= this->number || k<0) return false;

    for(auto& i: this->list[k]){
        i=std::toupper(i);
    }

#if IS_STD
    std::make_heap(this->heapLength.begin(), this->heapLength.end(),
            Comparator::sortbylength);
    std::make_heap(this->heapAlph.begin(), this->heapAlph.end(),
            Comparator::sortbyalph);
#else
    make_heap(this->heapLength.begin(), this->heapLength.end(),
            Comparator::sortbylength);
    make_heap(this->heapAlph.begin(), this->heapAlph.end(),
            Comparator::sortbyalph);
#endif

    return true;
};

bool Dish::truncate(int k, int i){
    k--; // hate kth string, but index is k-1, what a stupid API
    if(k >= this->number) return false;
    if(i >= (int)sizeof(this->list[k])) return true;

    this->list[k] = this->list[k].substr(0, i);

#if IS_STD
    std::make_heap(this->heapLength.begin(), this->heapLength.end(),
            Comparator::sortbylength); // TODO: ??
    std::make_heap(this->heapAlph.begin(), this->heapAlph.end(),
            Comparator::sortbyalph);
#else
    make_heap(this->heapLength.begin(), this->heapLength.end(),
            Comparator::sortbylength); // TODO: ??
    make_heap(this->heapAlph.begin(), this->heapAlph.end(),
            Comparator::sortbyalph);
#endif

    return true;
};

std::string Dish::getshortest(){
    return *this->heapLength[0];
};

std::string Dish::getfirst(){
    return *this->heapAlph[0];
};

// TODO: clean memory
