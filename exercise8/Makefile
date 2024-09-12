print_numbers : main.o random_int_in_range.o
	gcc -Wall -g -Og -o print_numbers main.o random_int_in_range.o
main.o : main.c
	gcc -c main.c
random_int_in_range.o : ../lib/random_int_in_range.c
	gcc -c ../lib/random_int_in_range.c
clean :
	rm print_numbers *.o
