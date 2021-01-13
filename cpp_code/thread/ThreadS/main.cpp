#include <thread>
#include <iostream>

#include "ThreadStudy.h"


int main( int arg, char *argv[]) {

	ThreadStudy thSD;
	
	thSD.func3();
	std::thread t1( &ThreadStudy::func1 );
	std::thread t2( &ThreadStudy::func2 );

	t1.detach();
	t2.detach();

	if ( t1.joinable() ) {
		t1.join();
	}

	if ( t2.joinable() ) {
		t2.join();
	}

	return 0;
}