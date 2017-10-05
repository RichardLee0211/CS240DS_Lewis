all: main.out

main.out: ExpandableList.h ExpandableList.cpp
	g++ -c ExpandableList.cpp -o ExpandableList.o
	g++ -c main.cpp -o main.o
	g++  main.o ExpandableList.o -o main.out
