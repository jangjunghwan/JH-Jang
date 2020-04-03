CC=g++
CFLAGS=-g -Wall
TARGET=test.out
OBJS=ringbuffer.cpp
OPTION=-std=c++11 -fpermissive

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(OPTION)

clean :
	rm -f $(TARGET)
