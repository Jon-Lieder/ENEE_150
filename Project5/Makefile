fraction.exe: fraction.o main.o
	gcc main.o fraction.o -o fraction.exe 

main.o: main.c fraction.h
	gcc -Wall -Wextra -c main.c

fraction.o: fraction.c fraction.h
	gcc -Wall -Wextra -c fraction.c

clean:
	rm -f main.o fraction.o fraction.exe fraction_results.txt 
