#include <iostream>

using namespace std;

int main()
{
    //int 변수 4byte
    //char 변수 1byte


    struct study
    {
        int ikor;
        int ieng;
        int iNumber;
    };
    



    cout << sizeof(int) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(int*) << endl;
    cout << sizeof(char*) << endl;
    cout << sizeof(float*) << endl;
    cout << sizeof(void) << endl;
    cout << sizeof(void*) << endl;

    char *pText = "나의 이름은 장중환";

    cout << pText << endl;
    cout << &pText[0] << endl;
    cout << (int*)pText << endl;

    study st ={};

    st.ikor = 100;
    cout << st.ikor << endl;
    
    study *pst = &st;

    (*pst).ikor = 12;
    cout << st.ikor << endl;

    pst->ikor = 13;
    cout << st.ikor << endl;

    pst->iNumber = 13;
    cout << st.iNumber << endl;


    /*
    void : 타입이 없다.
    어떠한 타입의 메모리 주소든 모두 저장 가능.
    단, 역참조가 불가능 하고 메모리 주소만 저장 가능하다.
    */



    void*   pvoid = &st.iNumber;

    cout << pvoid << endl;
    cout << *(&pvoid) << endl;

    return 0;
}