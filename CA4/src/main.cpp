#include<iostream>

#include"Dish.h"

int main(){
    Dish* myDish = new Dish();
    std::string str1 = "a?";
    std::string str2 = "ba?";
    std::string str3 = "cba?";
    std::string str4 = "dcba?";
    std::string str5 = "edcba?";
    myDish->insert(str1);
    myDish->insert(str2);
    myDish->insert(str3);
    myDish->insert(str4);
    myDish->insert(str5);

    // myDish->find(str1);
    // myDish->find(str2);
    // myDish->find(str3);

    myDish->allcaps(5);
    myDish->truncate(5, 3);

    std::string shortest = myDish->getshortest();
    std::string first = myDish->getfirst();

    return 0;
}
