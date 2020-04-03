#include <iostream>

using namespace std;

#define BUFFERSIZE 50

void circularArrayExample();

int main(){
    circularArrayExample();
}

void circularArrayExample(){
    int lastFiveNums[BUFFERSIZE] = {0};
    int currentIndex = 0;

    for(int i = 1; i <= 77; i++){
        lastFiveNums[currentIndex] = i;
        currentIndex++;
        
        if(currentIndex== 5) currentIndex = 0;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << lastFiveNums[i] << endl;
    }
    
}