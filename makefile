 # CFLAGS= -g -Wall -Wextra

grafexe: main.o komunikaty.o generator.o czytacz.o bfs.o queue.o dij.o pqmin.o
	$(CC) -g -o grafexe $^ 
clean:
	rm *.o
	rm grafexe
	rm test_czytacz
	rm log
	rm test_que
	rm test_BFS
	rm test_generator
test: test_czytacz.o czytacz.o 
	$(CC) -o test_czytacz $^
	$(CC) -o test_que test_que.c queue.c 
	$(CC) -o test_BFS bfs_test.c bfs.c queue.c czytacz.c 
	$(CC) -o test_generator test_generator.c generator.c czytacz.c
	./test_czytacz dane/mygraph
	./test_que
	./test_BFS dane/mydane1 8
	#./test_generator dane/ddgen
test2: 
	./test_czytacz dane/graph2x3
	

