# project name and intro
TARGET = Hello
OBJS = Hello_Class.o main.o
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
Hello_Class.o: Hello_Class.cpp Hello_Class.h
	$(CC) $(CFLAGS) Hello_Class.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o $(TARGET)

tar:
	tar -czvf projectname.tar.gz *.cpp *.h\
		Makefile README.md
