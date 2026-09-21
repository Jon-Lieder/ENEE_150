# --- CONFIG VARIABLES ---
CC = gcc                                                # Compiler
CFLAGS = -Wall -Wextra -g -Iinclude
LDLIBS = -lm
#CFLAGS = -Wall -Wextra -g -Iinclude -MMD -MP            # Compiler Flags
TARGET = bin/circuitTestAnalyzer.exe                    # Target Name

SRCS = $(wildcard src/*.c)                              # Compile all .c files
OBJS = $(patsubst src/%.c, obj/%.o, $(SRCS))                     # Generate .o output files
#DEPS = $(OBJ:.o=.d)                                     # Find all local custom header files

# --- TARGET RULES ---
# Rule to Link object files into the final executable
all: $(TARGET)

# Rule to link object files into the final executable
$(TARGET): $(OBJS) | bin
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDLIBS)

obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

# Target to clean up generated files and start fresh
clean: 
	rm -rf bin

.PHONY: clean
