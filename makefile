  #CFLAGS= -g -Wall -Wextra

grafexe: main.o komunikaty.o generator.o bfs.o queue.o pqmin.o dij.o czytacz.o
	$(CC) -g -o grafexe $^ 

clean:
	rm *.o
	rm grafexe
	rm test_czytacz
	rm log
	rm test_que
	rm test_BFS
	rm wyniki
test: test_czytacz.o czytacz.o 
	$(CC) -o test_czytacz $^
	$(CC) -o test_que test_que.c queue.c 
	$(CC) -o test_BFS bfs_test.c bfs.c queue.c czytacz.c 
	./test_czytacz dane/mygraph
	./test_que
	./test_BFS dane/mydane1 8

test2: test_czytacz.o czytacz.o 
	$(CC) -o test_czytacz $^
	./test_czytacz dane/graph2x3

testgen: main.o komunikaty.o generator.o czytacz.o dij.o bfs.o queue.o pqmin.o 
	$(CC) -o grafexe $^
	./grafexe -g wynik_testu_gen -p 10 -q 10 -f 0 -t 1000

testgen2: main.o komunikaty.o generator.o czytacz.o dij.o bfs.o queue.o pqmin.o 
	$(CC) -o grafexe $^
	./grafexe -g wynik_testu_gen -p 150 -q 150 -f 0.1 -t 1
	

