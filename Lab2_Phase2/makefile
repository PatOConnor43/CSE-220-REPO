# Here's some comments for the makefile. Here is where
# I learned how to write a makefile http://www.mrbook.org/tutorials/make

all: hello clean

hello: HelloWorld.o
	gcc HelloWorld.o -o hello

HelloWorld.o: HelloWorld.c
	gcc -c HelloWorld.c

clean:
	rm -rf *.o
 
