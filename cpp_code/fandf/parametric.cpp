#include <iostream>

using namespace std;


void greet(const char* str) {
    cout << str << endl;
}

void test(const char* str) {
    greet(str);
}

int main()
{
    greet("안녕!");

    return 0;
}