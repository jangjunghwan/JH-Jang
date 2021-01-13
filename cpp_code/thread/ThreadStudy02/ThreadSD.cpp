#include "ThreadSD.h"

ThreadSD::ThreadSD() {

}

//void ThreadSD::worker( int& counter ) {
//	for (int i = 0; i < 10000; i++)	{
//		counter += 1;
//	}
//


void ThreadSD::worker ( int& counter, std::mutex& m ) {
	for ( int i = 0; i < 10000; i++ ) {
		/*m.lock();
		counter += 1;
		m.unlock();*/
		/*아래와 같은 기능.*/

		std::lock_guard< std::mutex > lock(m);
	}
}