# project name and intro
TARGET = FBL
OBJS =  main.o \
		FBLUser.o FBLUserLL.o \
		FBLPost.o FBLPostLL.o \
		util.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

# Specifiy the target
all: $(TARGET)

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

# Specify how the object files should be created from source files
main.o: main.cpp FBLUser.h FBLUserLL.h util.h
	$(CC) $(CFLAGS) main.cpp

FBLUser.o: FBLUser.cpp FBLUser.h util.h
	$(CC) $(CFLAGS) FBLUser.cpp

FBLUserLL.o: FBLUserLL.cpp FBLUserLL.h util.h
	$(CC) $(CFLAGS) FBLUserLL.cpp

FBLPost.o: FBLPost.cpp FBLPost.h util.h
	$(CC) $(CFLAGS) FBLPost.cpp

FBLPostLL.o: FBLPostLL.cpp FBLPostLL.h util.h
	$(CC) $(CFLAGS) FBLPostLL.cpp

util.o: util.cpp util.h
	$(CC) $(CFLAGS) util.cpp

run:
	./FBL

test_run:
	cat test_input.txt | ./FBL

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o $(TARGET)
	# rm -f *.tar.gz

tar:
	tar -czvf projectname.tar.gz *.cpp *.h\
		Makefile README.md *.txt
	mkdir backup.d
	mv project.tar.gz backup.d
