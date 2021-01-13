#pragma once

#include <mutex>

class ThreadSD
{
public:
	ThreadSD();

	/*static void worker( int &counter);*/
	static void worker( int& counter, std::mutex& m );
};

