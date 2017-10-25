#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<algorithm>

#include"FBLUserLL.h"
#include"FBLUser.h"
#include"FBLPostLL.h"
#include"FBLPost.h"

using namespace std;

// A lazy implement, let all functions and classes could access useLL
// and in util.h, I add
// extern FBLUserLL* userLL;
FBLUserLL *userLL = new FBLUserLL();

int main(){
    userLL->mainLoop();
    delete userLL;
    return 0;
}
