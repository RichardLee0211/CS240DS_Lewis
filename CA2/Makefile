# project name and intro
TARGET = Donate
OBJS =  main.o Donor.o DonorDatabase.o
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
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Donor.o: Donor.cpp Donor.h
	$(CC) $(CFLAGS) Donor.cpp

DonorDatabase.o: DonorDatabase.cpp DonorDatabase.h
	$(CC) $(CFLAGS) DonorDatabase.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o $(TARGET)
	# rm -f *.tar.gz

tar:
	tar -czvf projectname.tar.gz *.cpp *.h\
		Makefile README.md
	mkdir backup.d
	mv project.tar.gz backup.d
