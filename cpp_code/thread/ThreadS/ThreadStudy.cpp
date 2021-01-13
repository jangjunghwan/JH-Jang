#include "ThreadStudy.h"


ThreadStudy::ThreadStudy() {

}

void ThreadStudy::func1() {
	for (int i = 0; i < 100; i++)
	{
		std::cout << "쓰레드 1 작동중" << std::endl;
	}
}

void ThreadStudy::func2() {
	for (int i = 0; i < 100; i++)
	{
		std::cout << "쓰레드 2 작동중" << std::endl;
	}
}

void ThreadStudy::func3() {
	for (int i = 0; i < 10; i++)
	{
		std::cout << "기본 작동중" << std::endl;
	}
}
