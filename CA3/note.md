this is note for this project, temporarily.
# note

## iostream
//TODO: ?? how to use test_input to test, it keeps loop
//cin.ignore(INT_MAX, '\n');
when use rediction >> in shell, stand input and output is changed.
in this case, I redict stand input from keyboard to file. So in the end of file, cin will be empty, and cin>>strCmd will be empty string, which may cause infinite loop.

//TODO: how to get FBLUser pointer?? inside a FLBUser::mainLoop
// like get access to FBLUser A while inside FBLUser B
while, I found three possible solutions
a. move FBLUser::mainLoop and FBLUserLL::mainLoop to main, then both of mainLoops could access to userLL in main
b. multi-thread coding, one for main thread, for userLL, and a new thread for each login user. HAHAHA, could be hard
c. make userLL global, genius, U are the best

//TODO: quickfix report, range-base 'for' loops are not allowd in C++98 mode
//how to mute this
from here, https://stackoverflow.com/questions/18158772/how-to-add-c11-support-to-syntastic-vim-plugin
maybe I should use clang++ and YCM


vector<FBLUser*> vecFriends;
//TODO: report corrupted double-linked list
list<string> *myFeed;
need more lookinto

//TODO: give seg fault
when have a pointer in class, constructor needs to implement this

_____ [ 10 pts ] LIKE
_____ [ 10 pts ] COMMENT
_____ [ 10 pts ] READ
_____ [ 10 pts ] READ_AZ
_____ [ 10 pts ] READ_ZA
__0___ [ 10 pts ] DLL - used vector of comments
_____ [ 10 pts ] USERS
_____ [ 10 pts ] SORTUSERS
__12___ [ 15 pts ] MISC - Naming convention
_____ [ 5 pts ] Attendance
