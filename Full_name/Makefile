fullname: main.o source.o
	gcc main.o source.o -o fullname.exe
	
main.o: main.c head.h
	gcc main.c -c
	
source.o: source.c head.h
	gcc source.c -c