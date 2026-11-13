CC = gcc
CFLAGS = -Wall -Wextra
TARGET = studentList.exe

HEADERS = $(wildcard *.h) 
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLASGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJS) $(TARGET)  
