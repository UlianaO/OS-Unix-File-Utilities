/*
List Files: Write a program that lists files in the given directory. When called without any 
arguments, the program should just print the file names. When invoked with the -l flag, the 
program should print out information about each file, such as the owner, group, 
permissions,  and  other  information  obtained  from  the  stat()  system  call.  The  program 
should take one additional argument, which is the directory to read, e.g., myls -l directory. 
If no directory is given, the program should just use the current working directory.   


Example output:
$ ./myls  
makefile 
myls 
mysearch 
mystat 
mytail 
myls-Wanwan.c 
mysearch-Wanwan.c 
mystat-Wanwan.c 
mytail-Wanwan.c 
*/


#include <sys/types.h>

#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
typedef struct dirent Dir;
typedef struct stat DirInfo;
typedef struct tm TimeInfo;
char* newString(int length) {
	return (char*)malloc(length*sizeof(char));
}

/*Encapsulation provided by professor Wanwan Li on Canvas */
int equals(char* string1, char* string2) {
	return strcmp(string1, string2)==0?1:0;
}

//takes in directory name
DirInfo getDirInfo(char* dir)  {
	DirInfo dirInfo;
	//system call
	stat(dir, &dirInfo);
	return dirInfo;
}

int main(int argc, char* argv[]) {

	//stat(), opendir(), readdir(), getcwd(). 

	//myls -l directory

	char* dirname;
	int flag = 0;

	printf("%d \n", argc);

	// if user provides 2 inputs -> ./myls -l
	
	if (argc > 2) {
		dirname = argv[2];      
		if (strcmp(argv[1], "-l")==0) {
			flag = 1;
		}	
	}
	else if (argc == 2) {
		dirname = ".";
		if (strcmp(argv[1], "-l")==0) {
			flag = 1;
		}

	}
	else
		dirname = ".";


	DIR* rootDir=opendir(dirname);

	if (rootDir == NULL) {
		printf("Directory does not exist");
		return 0;
	}
	Dir* dir=readdir(rootDir);

	for(; dir!= NULL; dir=readdir(rootDir))   {

		//get rid of current . and parent .. directory
		if ( (strcmp(dir->d_name, ".")==0) || (strcmp(dir->d_name, "..")==0) )
			//break;
			continue;

		if (flag == 0) { // no -l flag
			printf("Name: %s\n", dir->d_name); 
		}
		else {  // with -l flag, print details
			DirInfo dirInfo=getDirInfo(dir->d_name);

			printf("name: %s\t", dir->d_name); //file name
			printf("size: %6lu\t", (long) dirInfo.st_size);  //file size
			printf("permissions: "); 
				printf((S_ISDIR(dirInfo.st_mode)) ? "d" : "-");
				printf((dirInfo.st_mode & S_IRUSR) ? "r" : "-");
				printf((dirInfo.st_mode & S_IWUSR) ? "w" : "-");
				printf((dirInfo.st_mode & S_IXUSR) ? "x" : "-");
				printf((dirInfo.st_mode & S_IRGRP) ? "r" : "-");
				printf((dirInfo.st_mode & S_IWGRP) ? "w" : "-");
				printf((dirInfo.st_mode & S_IXGRP) ? "x" : "-");
				printf((dirInfo.st_mode & S_IROTH) ? "r" : "-");
				printf((dirInfo.st_mode & S_IWOTH) ? "w" : "-");
				printf((dirInfo.st_mode & S_IXOTH) ? "x" : "-");
				printf("   ");

			//print out owner`s name */
			printf("%d ", dirInfo.st_uid);
        		printf("%d \n", dirInfo.st_gid);
		}
	  }

	

return 0;
}