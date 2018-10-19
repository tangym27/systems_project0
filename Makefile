all: driver.o library.o linked_lists.o
	gcc -o out driver.o library.o linked_lists.o

driver.o: driver.c library.h linked_lists.h
	gcc -c driver.c

library.o: library.c linked_lists.h
	gcc -c library.c

linked_list.o: linked_lists.c
	gcc -c linked_lists.c

run:
	./out

clean:
	rm out
	rm *.o
