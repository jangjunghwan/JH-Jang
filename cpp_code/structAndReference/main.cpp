#include "test.h"

int main(int argc, char const *argv[])
{
	test TE;
	
	int Errocode;
	samples hSample;

	Errocode = TE.structReference(&hSample);
	if(Errocode != -1){
		cout << "ERRO" << endl;
	}

	cout << "input_int: " << hSample.first << endl;
	cout << "input_char: " << hSample.second << endl;

	return 0;
}