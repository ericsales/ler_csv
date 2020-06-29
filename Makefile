all:
	gcc -c csv.c
	gcc -o main main.c csv.o

run:
	./main

clear:
	rm *.o
	rm main
