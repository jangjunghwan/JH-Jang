#pragma once

#include <iostream>
#include <cstdio>
#include <thread>
#include <vector>

class ThreadVector
{
public:
	ThreadVector();

	static void worker( std::vector<int>::iterator start, 
				 std::vector<int>::iterator end, 
			     int *result );
	static void test();
};

