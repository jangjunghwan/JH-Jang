#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *rfp, *wfp;
	char buf[BUFSIZ];
	char n;

	//printf("%d", BUFSIZ);

	if((rfp = fopen("abc.txt", "r")) == NULL) {
		perror("fopen: abc.txt");
		exit(1);
	}

	if((wfp = fopen("ac.txt", "w")) == NULL) {
		perror("fopen : ac.txt");
		exit(1);
	}

	printf("%d",sizeof(char));


	while((n=fread(buf, sizeof(char) * 2, 1, rfp)) > 0) {
		fwrite(buf, sizeof(int), n, wfp);
	}

	fclose(rfp);
	fclose(wfp);

	return 0;
}