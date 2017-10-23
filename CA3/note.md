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
