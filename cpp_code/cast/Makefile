CC = g++

TARGET = start_cast

all = $(TARGET)

$(TARGET): main.o cast.o
	$(CC) -o $@ $^

main.o: cast.h main.cpp
	$(CC) -c -o $@ main.cpp 

cast.o: cast.h cast.cpp
	$(CC) -c -o $@ cast.cpp 



clean:
	rm -f *.o
