# Unix File Utilities Simulator
This project consist of 4 different programs based on various UNIX file utilities like stat, ls, tail and find.
______

**Mystat:** Calls stat() system call ona given file or directory: outputs size, numbers of blocks allocated, link count, file permissions, file inode. <br />

$ ./mystat ./makefile  <br /> 
File Information of ./makefile <br />
File Size: 259 Bytes <br />
Number of Blocks Allocated: 8 <br />
Number of Links: 1 <br />
File Permissions: -rw-r--r-- <br />
File Inode: -198486821 <br />


**List files:** Lists files in the given directory with the option of -l flag. <br />

$ ./myls <br />
makefile  <br />
myls-Uliana.c  <br />
mysearch-Uliana.c  <br />
mystat-Uliana.c  <br />
mytail-Uliana.c  <br />

**Tail:** Prints out the the last custom number of lines of a file.

$ ./mytail 2 ./makefile <br />
These are the last 2 lines of ./makefile: <br />
mytail: mytail-Uliana.c <br />
 gcc -o mytail mytail-Uliana.c <br />


**Recusrive search:** Prints out the names of each file and directory in
the file system tree, starting at a given point in the tree.<br />
$ ./mysearch <br />
Filename: makefile<br />
Filename: myls-Uliana.c<br />
Filename: mysearch-Uliana.c<br />
Filename: mystat-Uliana.c<br />
Filename: mytail-Uliana.c<br />
Search has finished!

