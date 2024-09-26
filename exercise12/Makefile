# Compiler
CC = gcc
CFLAGS = -Wall -g -I../lib/
SRCS = main.c ../lib/read_input.c
OBJS = $(SRCS:.c=.o)
TARGET = count_words

# Build the target with dependencies
$(TARGET).out : $(OBJS)
	@ echo "Building $(TARGET)\n"
	@ $(CC) $(CFLAGS) -o $(TARGET).out $(OBJS)

# Rule to compile each .c file into an object file
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# make clean
clean:
	@ rm -f $(OBJS) $(TARGET).out

# Zip for submission
zip: $(SRCS)
	@ mkdir -p _
	@ cp $(SRCS) _
	@ zip -r $(TARGET).zip _
	@ rm -rf _/
