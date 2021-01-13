#pragma once
#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

class ThreadQueue
{

public:
	ThreadQueue();

	static void producer( std::queue< std::string >* downloaded_pages, std::mutex* m,
						  int index );
	static void consumer( std::queue< std::string >* downloaded_pages, std::mutex* m,
		int* num_processed );

	static void consumerT(std::queue<std::string>* downloaded_pages, std::mutex* m, int* num_processed, std::condition_variable* cv);
};

