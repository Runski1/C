# Compiler
CC = gcc
CFLAGS = -Wall -g -I../lib/
SRCS = main.c ../lib/read_string.c ../lib/clear_input_buffer.c
OBJS = $(SRCS:.c=.o)
TARGET = read_file_numbers

# Build the target with dependencies
$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile each .c file into an object file
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# make clean
clean:
	rm -f $(OBJS) $(TARGET)

# Zip for submission
zip: $(SRCS)
	mkdir -p $(TARGET)
	cp $(SRCS) $(TARGET)
	zip -r $(TARGET).zip $(TARGET)
	rm -rf $(TARGET)/
