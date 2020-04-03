#include <iostream>
#include <fstream>

using namespace std;

static int zest();

char line[200];
char str[200];

int main(void)
{
 	zest();
}

int zest()
{
	ifstream infile;

	infile.open("result.txt");

	if (!infile.eof())
	{
		while (infile.getline(line, sizeof(line)))
		{
			cout << line << endl;
		}
	}
}