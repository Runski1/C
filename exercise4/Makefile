count_average : main.o read_integer.o
	gcc -Wall -g -Og -o count_average main.o read_integer.o
	rm *.o
main.o : main.c
	gcc -c main.c
read_integer.o : ../lib/read_integer.c
	gcc -Wall -g -Og -c ../lib/read_integer.c
clean :
	rm count_average main.o read_integer.o
