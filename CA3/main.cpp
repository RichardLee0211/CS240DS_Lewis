#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<algorithm>

#include"FBLUserLL.h"
#include"FBLUser.h"
#include"FBLPostLL.h"
#include"FBLPost.h"


using namespace std;

int main(){
    FBLUserLL userLL = new FBLUser();
    userLL.mainLoop();
    return 0;
}
