For 5 bonus points (toward your assignments grade)... 10 points if you submit before the end of your lab period! (You may not start before your lab period begins, please!)

Write a general purpose class called ExpandableList,
which contains a dynamically allocated array whose size is initially 10 elements.
If an 11th element is added to the list, the array should double in size, the items that were in the array should be copied to the new memory,
and the old memory that had been used for storage should be deleted.
You should implement
default,
value,
and copy constructors,
the assignment operator,
and the destructor.
Overload << and >> as friend functions (for cin and cout, not necessarily files, although the same code can be used for both!).
Your assignment operator and your copy constructor should make deep copies,
and you should submit a
test program that demonstrates that your code works.
At the top of your .h file for this class, you should include the following lines:


#typedef int ElementType

//#typedef float ElementType

Your code should work no matter which one is commented out. In other words, if I want the code to store floats instead of ints, I should only have to comment out the int typedef, and use the float version instead. Your test program that generates and inserts data may have to change as well, but NOT the rest of the ExpandableList class definition or implementation.

(This mini assignment is a precursor to C++ templates, and approximates the behavior of C++ vectors).
