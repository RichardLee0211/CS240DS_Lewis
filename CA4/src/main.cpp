#include<iostream>

#include"Dish.h"

int main(){
    Dish* myDish = new Dish();
    std::string str1 = "what?";
    std::string str2 = "do?";
    std::string str3 = "you?";
    std::string str4 = "think?";
    std::string str5 = "about?";
    myDish->insert(str1);
    myDish->insert(str2);
    myDish->insert(str3);
    myDish->insert(str4);
    myDish->insert(str5);

    return 0;
}
