test_main: main.c
	gcc -o test_main main.c

test_test: test.c
	gcc test_test.c -o test_test.exe

