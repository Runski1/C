dice_roller : main.o read_integer.o random_in_range.o
	gcc -Wall -g -Og -o dice_roller main.o read_integer.o random_in_range.o
	rm *.o
ex4_main.o : main.c
	gcc -c main.c
read_integer.o : ../lib/read_integer.c
	gcc -Wall -g -Og -c ../lib/read_integer.c
random_in_range.o : ../lib/random_in_range.c
	gcc -Wall -g -Og -c ../lib/random_in_range.c
clean :
	rm dice_roller *.o
