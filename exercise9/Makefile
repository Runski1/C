find_numbers : main.o random_int_in_range.o read_uint.o clear_input_buffer.o read_string.o
	gcc -Wall -g -Og -o find_numbers main.o random_int_in_range.o read_uint.o clear_input_buffer.o read_string.o
main.o : main.c
	gcc -c main.c
random_int_in_range.o : ../lib/random_int_in_range.c
	gcc -c ../lib/random_int_in_range.c
read_uint.o : ../lib/read_uint.c clear_input_buffer.o read_string.o
	gcc -c ../lib/read_uint.c
clear_input_buffer.o : ../lib/clear_input_buffer.c
	gcc -c ../lib/clear_input_buffer.c
read_string.o : ../lib/read_string.c
	gcc -c ../lib/read_string.c
clean :
	rm find_numbers *.o
