# This is the makefile for lister.exe
# I learned how to write a makefile http://www.mrbook.org/tutorials/make
#Nash Kleppan
#Vishal Mehta
#Patrick OConnor
#ASU Spring 2014

all: lister.exe clean

lister.exe: main.o print.o
	gcc main.o print.o -o lister.exe

main.o: main.c
	gcc -c main.c
	
print.o: print.c
	gcc -c print.c

clean:
	rm -rf *.o
 
