CC = gcc
CFLAGS = -Wall -g -I../lib/
SRCS = main.c functions/tui_functions.c functions/csv_functions.c functions/utils.c
OBJS = $(SRCS:.c=.o)
# Headers just for zipping the school assignment
HDRS = functions/macros.h functions/tui_functions.h functions/csv_functions.h functions/utils.h test.csv
OTHER = 
TARGET = csv_reader

# Build the target with dependencies, create target_name.out file (for .gitignore)
$(TARGET).out : $(OBJS)
	@ echo "Compiling the object files into executable $(TARGET).out"
	@ $(CC) $(CFLAGS) -o $(TARGET).out $(OBJS)
	@ echo "$(TARGET).out compiled."

# Rule to compile each .c file into an object file
%.o : %.c
	@ echo "Compiling $< into object file."
	@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	@ echo "Deleting object files and executables"
	@ rm -f $(OBJS) $(TARGET).out
	@ echo "Cleanup done."

# Zip for submission
zip: $(SRCS) $(HDRS)
	@ echo "Making a temporary directory."
	@ mkdir -p _
	@ echo "Copying source and header files into directory."
	@ cp $(SRCS) _
	@ cp $(HDRS) _
	@ echo "Zipping the directory."
	@ zip -r $(TARGET).zip _
	@ echo "Removing the temporary directory."
	@ rm -rf _/
	@ echo "Source files and headers packed into $(TARGET).zip"
