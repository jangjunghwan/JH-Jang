#include <iostream>

using namespace std;

typedef struct _samples
{
	int first;
	char* second;
}samples;



class test
{
public:
	test();
	int structReference(samples *hSample);

};