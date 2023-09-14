/*Write your own version of the command line program  stat, which simply calls the 
stat() system call on a given file or directory. Print out file size, number of blocks allocated, 
reference (link) count, file permissions, and file inode.   
Useful interfaces: stat()

$ ./mystat ./makefile 
File Information of ./makefile 
File Size: 259 Bytes 
Number of Blocks Allocated: 8 
Number of Links: 1 
File Permissions: -rw-r--r-- 
File Inode: -198486821  */


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, char* argv[]) {

	struct stat buf;
	int isStatGood;

	//directly use argv[1], assumption - input is correct, 
	//argc has to be 2: ./mystat filename
	if (argc == 2) {

		/*stat() sys call returns 0 if successful, -1 if error */
		isStatGood = stat(argv[1], &buf);

		if (isStatGood == 0) {
			// name --- printf("File size: %d\n", buf.st_size);
			printf("File size: %ld\n", (long) buf.st_size);
			printf("Number of Block Allocated: %lld\n", (long long) buf.st_blocks);
			printf("Number of Links: %ld\n", (long unsigned int) buf.st_nlink);
			printf("File permissions: %o ---> ", buf.st_mode);
			printf((S_ISDIR(buf.st_mode)) ? "d" : "-");
			printf((buf.st_mode & S_IRUSR) ? "r" : "-");
			printf((buf.st_mode & S_IWUSR) ? "w" : "-");
			printf((buf.st_mode & S_IXUSR) ? "x" : "-");
			printf((buf.st_mode & S_IRGRP) ? "r" : "-");
			printf((buf.st_mode & S_IWGRP) ? "w" : "-");
			printf((buf.st_mode & S_IXGRP) ? "x" : "-");
			printf((buf.st_mode & S_IROTH) ? "r" : "-");
			printf((buf.st_mode & S_IWOTH) ? "w" : "-");
			printf((buf.st_mode & S_IXOTH) ? "x" : "-");
			printf("\n");

			printf("File inode: %ld\n", (long unsigned int) buf.st_ino); 
		}
		
		else
			printf("Stat not good\n");
 	}
	else
		printf("argc is wrong");

return 0;
}