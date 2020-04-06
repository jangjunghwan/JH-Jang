CC = g++
TARGET = test
CFLAGS = -Wwrite-strings

all = $(TARGET)


$(TARGET): main.o test.o
	$(CC) -o $@ $^
main.o: test.h main.cpp
	$(CC) -c -o $@ main.cpp

test.o: test.h test.cpp
	$(CC) -c -o $@ test.cpp $(CFLAGS)



clean:
	rm -f *.o test
