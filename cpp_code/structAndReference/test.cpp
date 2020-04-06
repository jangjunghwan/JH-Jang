#include "test.h"

test::test(){

}

int test::structReference(samples *hSample){
    

    hSample->first = 1;
    hSample->second = "Hello world";

    return -1;
}