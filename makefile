all: mystat mytail myls mysearch

mystat: mystat-Uliana.c
	gcc -o mystat mystat-Uliana.c

mytail: mytail-Uliana.c
	gcc -o mytail mytail-Uliana.c

myls: myls-Uliana.c
	gcc -o myls myls-Uliana.c

mysearch: mysearch-Uliana.c
	gcc -o mysearch mysearch-Uliana.c