money_guesser.out : main.o read_positive.o clear_input_buffer.o read_string.o
	gcc -Wall -g -Og -o money_guesser.out main.o read_positive.o clear_input_buffer.o read_string.o
main.o : main.c
	gcc -c main.c
read_positive.o : ../lib/read_positive.c 
	gcc -Wall -g -Og -c ../lib/read_positive.c 

read_string.o : ../lib/read_string.c
	gcc -Wall -g -Og -c ../lib/read_string.c 

clear_input_buffer.o : ../lib/clear_input_buffer.c
	gcc -Wall -g -Og -c ../lib/clear_input_buffer.c
clean :
	rm money_guesser.out *.o
