this is note for this project, temporarily.
# note

//TODO: ?? how to use test_input to test, it keeps loop
//cin.ignore(INT_MAX, '\n');
when use rediction >> in shell, stand input and output is changed.
in this case, I redict stand input from keyboard to file. So in the end of file, cin will be empty, and cin>>strCmd will be empty string, which may cause infinite loop.
