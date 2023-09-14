/*
Uliana Ozerova
Write a program that prints out the names of each file and directory in 
the file system tree, starting at a given point in the tree.  For example, when run without 
arguments,  the  program  should  start  with  the  current  working  directory  and  print  its 
contents, as well as the contents of any sub-directories, etc., until the entire tree, root at the 
CWD, is printed. If given a single argument (of a directory name), use that as the root of 
the tree instead. 

*/ 

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

typedef struct dirent Dir;
typedef struct stat DirInfo;


void recursiveSearch(char* path, int indent) {
        char buffer[1000];

	DIR *rootDir = opendir(path);
	Dir* dir;
	if (rootDir == NULL) return;

	for(dir=readdir(rootDir); dir!=NULL; dir=readdir(rootDir)) {
		
		if (strcmp(dir->d_name, ".")==0 || strcmp(dir->d_name, "..")==0 ) continue;
		//printf("%*s%s\n", indent*3,"", path); //prints the whole pass
		
		//construct the path, copy to buffer to avoid segmentation fault
		strcpy(buffer, path);
		strcat(buffer, "/");
		strcat(buffer, dir->d_name);

		//print the name of the current file
		printf("%*s%s\n", indent*3,"", dir->d_name);
		recursiveSearch(buffer, indent+1);
	}
	closedir(rootDir);

}
int main(int argc, char* argv[]) {


	if (argc > 2) {
		printf("Wrong number of arguments. Usage: /mysearch or /mysearch nameofdirectory");
		return 0;
	}
	else if (argc == 2) {
		recursiveSearch(argv[1], 0);
	}
	else {
		// use current directory
		recursiveSearch(".", 0);
	}
		
return 0;
}