#include <iostream>
#include <fstream>

using namespace std;

static int tread(char line[200]);

#define BUFFER_SIZE 200

int main()
{

    tread();
}

static int tread(char **val)
{
    ifstream ifile;
    char line[200]; // 한 줄씩 읽어서 임시로 저장할 공간
       
    ifile.open("result.txt");  // 파일 열기

    if (ifile.is_open())
    {
        while (ifile.getline(line, sizeof(line))) // 한 줄씩 읽어 처리를 시작한다.
        {
            cout << line << endl; // 내용 출력
        }
    }

    ifile.close(); // 파일 닫기

    return 0;
}