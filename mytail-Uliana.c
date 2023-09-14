/*
Uliana Ozerova
Tail: Write a program that prints out the last few lines of a file. The program should be 
efficient, in that it seeks to near the end of the file, reads in a block of data, and then goes 
back until it finds the requested number of lines; at this point, it should print out those lines 
from the beginning to the end of the file. To invoke the program, one should type: mytail 
-n file, where n is the number of lines at the end of the file to print.

stat(), lseek(), open(), read(), close().
*/ 

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]) {

	int file_fd;  // for system calls
	char* fileName;
	char charType[1]; // for lseek
	char* buffer[10000]; // to hold the tail

	/*   /mytail -2 ./makefile WHERE 2 is the number of lines */
	if (argc != 3) {
		printf("Wrong number of arguments: format /mytail -2 ./makefile ");
		return 0;
	}

	fileName = argv[2];
	file_fd = open(fileName, O_RDONLY);
	
	/*seek to near the end of file*/
	lseek(file_fd, -1, SEEK_END); //return the size of the file

	int numLines = atoi(argv[1]); // a negative number

	/* going backwards untill finds the requested number of lines, one 0 - no more lines left to read */
	while (numLines < 0) { 
		// use read() system call, read one byte at a time
		read(file_fd, charType, 1);
		if (*charType == '\n') numLines++;

		// seek ony byte backwards
		lseek(file_fd, -2, SEEK_CUR);
	}

	// lseek at the requested line from the bottom, read the file.
	while ( read(file_fd, buffer, 1) ) {
		printf("%s", buffer);
	}
	printf("\n");

	close(file_fd);
	
return 0;
}