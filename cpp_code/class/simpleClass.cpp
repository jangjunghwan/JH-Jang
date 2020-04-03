#include <iostream>
#include <cstring>

using namespace std;

/*
클래스의 4가지 속성
캡슐화: 클래스 안에 속하는 여러 변수 혹은 함수를 하나의 클래스로 묶어주는 기능.
은닉화: 클래스 안에 속하는 변수 혹은 함수를 원하는 부분만 외부에 공개 또는 비공개 할 수 있는 기능.
    - public: 클래스 내부와 외부에서 모두 접근 가능한 방법.
    - protected: 클래스 외부에서는 접근이 불가능하고 
                 자기자신 내부나 
                 자식 클래스 내부에서는 접근이 가능.
    - private: 자기자신 내부에서만 접근이 가능하고 
               외부나 자식 내부에서는 접근이 불가능한 방법.

상속성: 클래스는 클래스와 클래스간에 부모, 자식 관계를 형성할 수 있다.
        자식 클래스는 부모 클래스의 멤버를 물려받아 자신의 것처럼 사용할 수 있다.
        단, private으로 되어 있는 멤버에는 접근이 불가능 하다.

다형성: 부모 자식관계로 상속관계가 형성되어 있는 클래스간에 
        서로 형변화이 가능한 성질을 말한다.

생성자: 어떤 클래스를 이용해서 객체를 생성할때 자동으로 호출되는 함수이다.
        객체 생성시 호출되는 함수이기 때문에 객체의 멤버변수를 초기화할 때
        융요하게 상용 할 수 있다.
        생성자를 만들어주지 않을 경우 내부적으로 기본 생성자가 제공이 되어서
        기본 생성자를 자동으로 호출해주게 된다.
        // 클래스명()
        {
        }
        의 형태로 선언된다.

소멸자: 어떤 클래스를 이용해서 생성한 객체가 메모리에서 해체될때
        다종으로 호출되는 함수이다. 객체를 사용하고 난 뒤 마무리
        작업 해줄때 유용하게 사용할 수 있다.


*/

class CTracer
{
    // 클래스 멤버변수를 선언할 때는 m_를 붙여준다.(자기 방식)
    char m_strName[32];
public:
CTracer(){ // 생성자.
    cout << "생성자" << endl;
}

CTracer(char* pName)
{

    strcpy(m_strName, pName);
    cout << m_strName << endl;
}

CTracer(char* pName, int iFlash, int iBack):
    m_iBack(iBack),
    m_iFlash(iFlash)
    {
        strcpy(m_strName, pName);

        cout << "wkdwnd" << endl;
    }

~CTracer(){ // 소멸자.
    cout << "소멸자" << endl;
}

public: // public 키워드 아래에 있는 멤버는 모두 외부에서 접근이 가능하다.
    int m_iAttack;
    int m_iHp;
    int test(){
        cout << "test" << endl;
    }

private:
    int m_iFlash;
    int m_iBack;

};

int main()
{
    //CTracer tr1;
    CTracer tr1("한조", 1, 2);

    tr1.m_iAttack;
    tr1.test();

    return 0;
}