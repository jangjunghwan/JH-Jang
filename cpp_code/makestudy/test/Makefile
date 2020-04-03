CC = g++

TARGET = start


test.o: test.h test.cpp
	$(CC) -o $@ -c test.cpp
main.o: test.h main.cpp
	$(CC) -o $@ -c main.cpp

all = $(TARGER)
all: main.o test.o
	$(CC) -o $@ main.o test.o

#-------------------------------
clean:
	rm -r *.o

