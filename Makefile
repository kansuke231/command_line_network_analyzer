output: data_import.o main.o
	gcc main.o data_import.o -o output
data_import.o: data_import.c
main.o: main.c