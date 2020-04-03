#include <iostream>
#include <cstring>

using namespace std;

#define NAME_SIZE 32

struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main(){
	 _tagStudent tStudent = {}; // NULL 값으로 초기화
	//_tagStudent tStudent;

	//_tagStudent tStudentArr[100] = {}; 

	tStudent.iKor = 100;
	//한글:8개*2byte 16byte
	//space: 2개*1byte 2byte
	//특수문자: 1개*1byte 1byte
	//영어: x*1byte 0byte
	strcpy(tStudent.strName, "나는 장중환 입니다.");

	char arr[NAME_SIZE] = "나는 장중환 입니다.";
	//strcpy(arr, "나는 장중환 입니다.");

	if (strcmp(tStudent.strName, arr) == 0){
		cout << "같은 문자입니다." << endl;
	}

	cout << "이름:" << tStudent.strName << endl;
	cout << "이름 크기:" << strlen(tStudent.strName) << endl;
	cout << "학번:" << tStudent.iNumber << endl;
	cout << "국어:" << tStudent.iKor << endl;
	cout << "영어:" << tStudent.iEng << endl;
	cout << "수학:" << tStudent.iMath << endl;
	cout << "합:" << tStudent.iTotal << endl;
	cout << "평균:" << tStudent.fAvg << endl;

	return 0;
}