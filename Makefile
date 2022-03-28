grafexe: main.o komunikaty.o generator.o
	$(CC) -o grafexe $^
clean:
	rm *.o
	rm grafexe
	rm test
	rm wyniki
test: test_czytacz.c czytacz.o
	$(CC) -o test $^
	
test_run:	
	./test dane_test_write_to_file wyniki

