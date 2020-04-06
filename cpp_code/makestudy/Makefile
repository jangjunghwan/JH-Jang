CC = g++
TARGET = a.out


all = $(TARGET)

$(TARGET): main.o ve_class.o
	$(CC) -o $@ $^
main.o: inc/ve_class.h src/main.cpp
	$(CC) -c -o $@ src/main.cpp

ve_class.o: inc/ve_class.h src/ve_class.cpp
	$(CC) -c -o $@ src/ve_class.cpp



clean :
	rm -f *.o a.out
