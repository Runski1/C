cheating_game : main.o read_integer.o read_range.o
	gcc -Wall -g -Og -o cheating_game main.o read_integer.o read_range.o
	rm *.o
main.o : main.c
	gcc -c main.c
read_integer.o : ../lib/read_integer.c
	gcc -Wall -g -Og -c ../lib/read_integer.c
read_range.o : ../lib/read_range.c ../lib/read_integer.c
	gcc -Wall -g -Og -c ../lib/read_range.c
clean :
	rm cheating_game main.o read_integer.o read_range.o
