#include "ThreadQueue.h"

ThreadQueue::ThreadQueue() {

}

void ThreadQueue::producer(std::queue< std::string >* downloaded_pages, std::mutex* m,
	int index ) {
	for (int i = 0; i < 5; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
		std::string content = "website: " + std::to_string(i) + " from thread(" + std::to_string(index) + ")\n";

		m->lock();
		downloaded_pages->push(content);
		m->unlock();
	}
}

void ThreadQueue::consumer(std::queue< std::string >* downloaded_pages, std::mutex* m,
	int* num_processed ) {

	while ( *num_processed < 25 ) {
		m->lock();

		if (downloaded_pages->empty()) {
			m->unlock();

			std::this_thread::sleep_for( std::chrono::milliseconds( 10 ));
			continue;
		}
		std::string content = downloaded_pages->front();
		downloaded_pages->pop();

		(*num_processed)++;
		m->unlock();

		std::cout << content;
		std::this_thread::sleep_for(std::chrono::milliseconds( 80 ));
	}
}

void ThreadQueue::consumerT(std::queue<std::string>* downloaded_pages, std::mutex* m, 
							int* num_processed, std::condition_variable* cv) {
	while ( *num_processed < 25 ) {
		std::unique_lock< std::mutex > lk( *m );

		cv->wait(lk, [&] {return !downloaded_pages->empty() || *num_processed == 25; });
	}
}