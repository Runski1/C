count_characters : main.o read_string.o clear_input_buffer.o
	gcc -Wall -g -Og -o count_characters main.o read_string.o clear_input_buffer.o
main.o : main.c
	gcc -c main.c
read_string.o : ../lib/read_string.c
	gcc -c ../lib/read_string.c
clear_input_buffer.o : ../lib/clear_input_buffer.c
	gcc -c ../lib/clear_input_buffer.c
clean :
	rm count_characters *.o
