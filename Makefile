output: data_import.o main.o
	gcc main.o data_import.o DFS.o -o output
DFS.o: DFS.c
	gcc DFS.c -c
data_import.o: data_import.c
	gcc data_import.c -c
main.o: main.c
	gcc main.c -c 
