# cs240mytest
this is just a repository for my cs240 class code assignment.
=======================================================================
TOPICS FOR EXAM 1 INCLUDE (but may not be limited to!) THE FOLLOWING:
=======================================================================
C++ PROGRAM DEVELOPMENT
- understand what kind of code is in .o, .h, .cpp files
- understand what make and g++ do (in terms of their input
        and output files
        - understand the purpose of using a makefile
        - understand what is meant by "linking" and "compiling"
        - know what a unix shell (terminal) is
        - know basically what tar and gzip do
        - understand "what goes where" in terms of class definitions,
        implementations, compiling statements, etc., and C++ programs
        that use classes, objects, and separate compilation

        PROCEDURES (FUNCTIONS)
        - know what a function signature is, and the difference between
        a function signature and a function implementation
        - understand the implications of the different parameter passing
        styles (by value, by reference, by constant reference)
        - know the syntax for specifying these styles in C++

        STREAMS
        - know what is meant by a "stream" in C++
        - know the difference between File streams and I/O streams (cin and cout)
        - Be able to use and understant the extraction (>>) and insertion (<<)
    operators for getting base types into and out of streams
    - know what a C++ string class is (but don't worry about the details
            of exactly how it is used)

    TYPES and OPERATORS
    - understand what is meant by "Abstract Data Type"
    - know what "encapsulation" and "abstraction" mean, in terms of
    C++ types and classes, and know the difference between the
    "definition" of a type, and its "implementation"
    - know what an operator is, and what the following C++ operators
    do on built in types: +, -, *, /, <, >, <=, ==, !=, >=
    - know what typedef and enum do (but don't worry too much about these)

    POINTERS and DYNAMICALLY ALLOCATED MEMORY
    - know the difference between a pointer and a variable with
associated storage (in memory)
    - know how to use new and delete to dynamically allocate and return memory
    - understand the relationship between pointers and addresses, and how
    to do "pointer arithmetic" to change what a pointer points to
    - understand how to create arrays and access array elements, both
    dynamically and statically

    C++ CLASSES and OBJECTS
    - know the difference between classes and objects
    - know what a class definition looks like, and what the various parts
    are (class name, member functions, data members, public and private
            areas, constructors, destructor, accessor functions, etc.)
    - know the difference between the different kinds of constructors
    (default, value, and copy), and when they are called
    - know when the destructor is called and when it is important to implement
    it yourself vs. letting the compiler generate it
    - understand what is meant by operator overloading... know how to do it
in C++ (the syntax for an overloaded operator)
    - know what a "friend" function is, where it goes in code, what makes
    it a friend function (as opposed to just a regular function or a
            member function of a class), and how (syntax) and why you might want
    to use it
    - understand why the extraction and insertion operators cannot be overloaded
    for a class, and why they therefore need to be implemented as friend
    functions (but don't worry about memorizing the exact syntax for doing
            this)

    MEMORY
    - know the difference between heap, stack, and static memory
- understand where variables will reside (i.e. in which type of memory)
    when they're declared in different ways (as procedure parameters, local
            variables, global variable, dynamically allocated variables, data members
            of a class, etc.)
    - understand what a "memory leak" is, and how to identify it in a program
    I might give you, and how to fix/avoid it
    - know the difference between a shallow copy and a deep copy.  Which one
    can the compiler do "automatically" and which one do you have to write
    on your own?
    - understand the concept of the "lifetime" of a variable, including
    parameters, local variables in functions, and global variables.

    CONTAINERS and LISTS (the below list assumes we get to all this on 9/25 and 9/27...
            bottom few items may be omitted... check back here)
    - understand what is meant by a container, and how one can be organized
    in different ways
    - know how to implement a "list" class with static arrays, dynamic arrays,
    and linked lists.  Understand the implications of doing it in these
    various ways.
    - be able to "read" linked list code, including Nodes, next pointers,
    and the * and -> operators
    - know that every combination of variables with *'s and ->'s around it
    refers to a value, at some address, that has a type... be able to figure
    out which value and address is referred to by combinations of these
    operators
    - be able to write simple linked list insert, remove, and traversal code
    - know what a null pointer is, and what the problem with dereferencing
    a bad pointer is
