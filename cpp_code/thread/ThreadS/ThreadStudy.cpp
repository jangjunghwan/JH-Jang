#include "ThreadStudy.h"


ThreadStudy::ThreadStudy() {

}

void ThreadStudy::func1() {
	for (int i = 0; i < 100; i++)
	{
		std::cout << "������ 1 �۵���" << std::endl;
	}
}

void ThreadStudy::func2() {
	for (int i = 0; i < 100; i++)
	{
		std::cout << "������ 2 �۵���" << std::endl;
	}
}

void ThreadStudy::func3() {
	for (int i = 0; i < 10; i++)
	{
		std::cout << "�⺻ �۵���" << std::endl;
	}
}
