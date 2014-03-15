# This is the makefile for lab3.exe
# I learned how to write a makefile http://www.mrbook.org/tutorials/make
#Nash Kleppan
#Vishal Mehta
#Patrick OConnor
#ASU Spring 2014

all: lab3.exe clean

lab3.exe: main.o print.o scanner.o
	gcc main.o print.o -o lab3.exe

main.o: main.c
	gcc -c main.c
	
print.o: print.c
	gcc -c print.c

scanner.o: scanner.c
	gcc -c scanner.c

clean:
	rm -rf *.o
 
