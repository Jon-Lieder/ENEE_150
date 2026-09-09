# --- CONFIG VARIABLES ---
CC = gcc                                                # Compiler
CFLAGS = -Wall -Wextra -g -Iinclude
LDLIBS = -lm
#CFLAGS = -Wall -Wextra -g -Iinclude -MMD -MP            # Compiler Flags
TARGET = bin/circuitTestAnalyzer.exe                    # Target Name

SRCS = $(wildcard src/*.c)                              # Compile all .c files
#OBJS = $(patsubst src/%.c, build/%.o, $(SRCS))                     # Generate .o output files
#DEPS = $(OBJ:.o=.d)                                     # Find all local custom header files

# --- TARGET RULES ---
# Rule to Link object files into the final executable
all: $(TARGET)

# Rule to link object files into the final executable
$(TARGET): $(SRCS) | bin
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDLIBS)

#build/%.o: src/%.c | build
#	$(CC) $(CFLAGS) -c $< -o $@

# Target to clean up generated files and start fresh
clean: 
	rm -rf bin

.PHONY: clean
