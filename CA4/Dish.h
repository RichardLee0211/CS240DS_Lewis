#include<iostream>
#include<string>

class Dish{
    private:
        std::string heapLength[1024];
        std::string heapAlph[1024];

    public:
        int insert(std::string s);
        int find(std::string s);
        bool capitalize(int k);
        bool allcaps(int k);
        bool truncate(int k, int i);
        std::string getshortest();
        std::string getfirst();

};
