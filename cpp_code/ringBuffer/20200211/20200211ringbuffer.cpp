#include <iostream>
#include <array>
#include <thread>

using namespace std;



// 상수 정의하는 방법
const size_t BUFFERSIZE = 5;
const int TESTCODE = 1;

#define NEXT(index)   ((index+1)%BUFFERSIZE)
// #define BUFFERSIZE 10

// define, const 다른점

typedef struct _INDEXCHECK
{
	int head;
	int tail;
}INDEXCHECK;

static size_t queueInit(INDEXCHECK *numCheck);
static size_t bufferInit(size_t **ringBuffer);
static int empBufCheck(INDEXCHECK *numCheck);
static int push(size_t *buffer, size_t *thbuffer, INDEXCHECK *numCheck, size_t data); //buffer에 값 넣기
static int indexFullCheck(INDEXCHECK *numCheck);
static int pull(size_t *buffer, INDEXCHECK *numCheck, int *checkpoint); //buffer에 값 가져오기


static size_t queueInit(INDEXCHECK *numCheck){
	numCheck->head = numCheck->tail = 0;
}

static size_t bufferInit(size_t **ringBuffer) {
	size_t* buffer = new size_t[BUFFERSIZE];
	*ringBuffer = buffer;

	//추후 할당 내용 적용 해제 하기 추가하기  (calloc)
}

static int empBufCheck(INDEXCHECK *numCheck){ //head, tail이 비엇을 때(1) 아닐때(0) 
	return numCheck->head == numCheck->tail;
}

static int push(size_t *buffer, size_t *thbuffer, INDEXCHECK *numCheck, size_t data){
	if(indexFullCheck(numCheck) == 1){
		cout << "array Full(overflow)" << endl;

	}
	buffer[numCheck->tail] = data;
	numCheck->tail = NEXT(numCheck->tail);
}

static int indexFullCheck(INDEXCHECK *numCheck){
	// cout << "head:" << numCheck->head << endl;
	// cout << "tail:" << numCheck->tail << endl;
	if (NEXT(numCheck->tail) == numCheck->head){
		return 1;
	}
}

static int pull(size_t *buffer, INDEXCHECK *numCheck, int *checkpoint){
	if (empBufCheck(numCheck)){
		cout << "array empty(underflow)" << endl;
		return 0;
	}
	*checkpoint = buffer[numCheck->head];
	numCheck->head = NEXT(numCheck->head);
	//return checkpoint;
}


int main(){
	cout << "/*start*/" << endl;
	INDEXCHECK numCheck;
	size_t *etBuffer;
	size_t *thrBuffer;
	int checkpoint;
	int thStart;
	int stop;

	queueInit(&numCheck); // q struct init
	bufferInit(&etBuffer); // buffer init
	bufferInit(&thrBuffer);

	size_t data[BUFFERSIZE] = {1, 2, 3, 4, 5};
	push(etBuffer, thrBuffer, &numCheck, data);
//---------------------good line---------------------

	while(!empBufCheck(&numCheck)){ // !empBufCheck: 1
		stop = pull(etBuffer, &numCheck, &checkpoint);
		if (stop == 0){
			break;
		}
	}
	for (int i = 0; i < BUFFERSIZE; i++){
		cout << etBuffer[i]	<<endl;
	}
}

