#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int fdin, fdout;
	void* c;
	fdin = open(argv[1], O_RDONLY);
	if (fdin<0){
		fprintf(stderr, "Unable to open file: %m");
		return -1;
	}
	fdout = open(argv[2], O_CREAT|O_TRUNC|O_WRONLY|O_APPEND);
	if (fdout<0){
		fprintf(stderr, "Unable to open file: %m");
		return -1;
	}
	read(fdin, c, 1);
	while (c != EOF)
	{
		read(fdin, c, 1);
		write(fdout, c, 1);
	}
	return 0;
}
