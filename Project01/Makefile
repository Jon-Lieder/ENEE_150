# --- CONFIG VARIABLES ---
CC = gcc                                                # Compiler
CFLAGS = -Wall -Wextra -g -Iinclude -MMD -MP            # Compiler Flags
TARGET = bin/main                                       # Target Name

SRCS = $(wildcard src/*.c)                              # Compile all .c files
OBJS = $(patsubst src/%.c, build/%.o, $(SRCS))         # Generate .o output files
DEPS = $(OBJ:.o=.d)                                     # Find all local custom header files

# --- TARGET RULES ---
# Rule to Link object files into the final executable
all: $(TARGET)

# Rule to link object files into the final executable
$(TARGET): $(OBJS) | bin
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

# Target to clean up generated files and start fresh
clean: 
	rm -rf $(OBJS) $(TARGET) 

.PHONY: clean
