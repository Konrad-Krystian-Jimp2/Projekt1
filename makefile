  #CFLAGS= -g -Wall -Wextra

grafexe: main.o komunikaty.o generator.o bfs.o queue.o pqmin.o dij.o czytacztemp.o
	$(CC) -g -o grafexe $^ 
dij.c:

clean:
	rm *.o
	rm grafexe
	rm test_czytacz
	rm log
	rm test_que
	rm test_BFS
	rm test_gen
test: test_czytacz.o czytacz.o 
	$(CC) -o test_czytacz $^
	$(CC) -o test_que test_que.c queue.c 
	$(CC) -o test_BFS bfs_test.c bfs.c queue.c czytacz.c 
	$(CC) -o test_gen test_gen.c czytacz.c generator.c
	./test_czytacz dane/mygraph
	./test_que
	./test_BFS dane/mydane1 8
	./test_gen
test2: 
	./test_czytacz dane/graph2x3
	

