all:	lists.o testLists.o 
	gcc -o test testLists.o lists.o

lists.o: lists.c
	gcc -c lists.c

testLists.o: testLists.c lists.h
	gcc -c testLists.c

run:
	./test

clean:
	rm test
	rm *.o