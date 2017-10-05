#ifndef EXANDABLELIST_H
#define EXANDABLELIST_H

using namespace std;
typedef int ElementType;
//typedef float ElementType;

class ExpandableList{
private:
    ElementType* list;
    int listSize;
    int listUsedSize;

private:
    int doubleListSize();

public:
    ExpandableList();
    ~ExpandableList();
    ExpandableList(ExpandableList& mylist);
    ExpandableList& operator=(const ExpandableList& mylist);
    int add(ElementType addEle=0);
    int printAll();
    ostream& operator<<(ostream& os, const ExpandableList& mylist);
    istream& operator>>(istream& is, ExpandableList& mylist);



};

#endif
