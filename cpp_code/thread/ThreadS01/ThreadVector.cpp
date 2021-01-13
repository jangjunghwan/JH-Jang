#include "ThreadVector.h"

ThreadVector::ThreadVector() {

}

void ThreadVector::worker( std::vector<int>::iterator start, std::vector<int>::iterator end, int *result ) {
	
	int sum = 0;
	for ( auto itr = start; itr < end; ++itr ) {
		sum += *itr;
	}

	*result = sum;

	std::thread::id this_id = std::this_thread::get_id();

	printf("������%x ���� %d ���� %d ���� ����� ���: %d \n", 
				  this_id, * start, * (end - 1), sum);
}

void ThreadVector::test() {
	std::cout << "hi" << std::endl;
}