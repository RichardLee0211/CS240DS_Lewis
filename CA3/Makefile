# project name and intro
TARGET := FBL
OBJDIR := bin
OBJS :=  $(addprefix $(OBJDIR)/, main.o \
		FBLUser.o FBLUserLL.o \
		FBLPost.o FBLPostLL.o \
		util.o)
CC := g++
DEBUG := -g
CFLAGS := -Wall -c $(DEBUG)
LFLAGS := -Wall $(DEBUG)

# Specifiy the target
all: $(TARGET)

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

# objects
$(OBJS) : | $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/main.o: main.cpp FBLUserLL.h util.h
	$(CC) $(CFLAGS) $< -o $@

$(OBJDIR)/FBLUser.o: FBLUser.cpp FBLUser.h util.h
	$(CC) $(CFLAGS) $< -o $@

$(OBJDIR)/FBLUserLL.o: FBLUserLL.cpp FBLUserLL.h util.h
	$(CC) $(CFLAGS) $< -o $@

$(OBJDIR)/FBLPost.o: FBLPost.cpp FBLPost.h util.h
	$(CC) $(CFLAGS) $< -o $@

$(OBJDIR)/FBLPostLL.o: FBLPostLL.cpp FBLPostLL.h util.h
	$(CC) $(CFLAGS) $< -o $@

$(OBJDIR)/util.o: util.cpp util.h
	$(CC) $(CFLAGS) $< -o $@

# run and test
run:
	./$(TARGET)

test:
	cat test_input.txt | ./$(TARGET)

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
	# rm -f *.tar.gz

tar:
	tar -czvf projectname.tar.gz *.cpp *.h\
		Makefile README.md *.txt
	mkdir backup.d
	mv project.tar.gz backup.d
