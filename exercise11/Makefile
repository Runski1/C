replace_characters.out : main.o read_string.o clear_input_buffer.o replace_char.o
	gcc -Wall -g -Og -o replace_characters.out main.o read_string.o clear_input_buffer.o replace_char.o
main.o : main.c
	gcc -c main.c
read_string.o : ../lib/read_string.c
	gcc -c ../lib/read_string.c
clear_input_buffer.o : ../lib/clear_input_buffer.c
	gcc -c ../lib/clear_input_buffer.c
replace_char.o : ../lib/replace_char.c
	gcc -c ../lib/replace_char.c
clean :
	rm replace_characters.out *.o
