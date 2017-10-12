#include<iostream>
#include<vector>
#include<fstream>
#include<cstring>


using namespace std;

#define DONORS_MAX 1000

void splitString(const std::string& s, std::vector<std::string>& v, const std::string& c){
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
};

bool isHaveSpecialChar(const char *Str){
    char str[] = "\t, \n, !, @, #, $, %, ^, &, *, (, ), -, =, _, +";
    char Temp[256];
    char *p;
    strcpy(Temp,Str);
    for(unsigned int i = 0;i < strlen(str);i++)
    {
        p =  strchr(Temp, str[i]);
        if(p != NULL)
        {
            return true;
        }
    }
    return false;
}

bool existsFile (const std::string& name) {
        ifstream f(name.c_str());
        return f.good();
}
