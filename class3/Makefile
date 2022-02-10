# for C
CC = gcc
CFLAGS = -Wall
# for C++
# CXX = g++
# CXXFLAGS = -Wall

hello: hello.o factorial.o greeting.o
	$(CC) hello.o factorial.o greeting.o -o hello

hello.o: hello.c
	$(CC) $(CFLAGS) -c hello.c

greeting.o: greeting.c
	$(CC) $(CFLAGS) -c greeting.c

factorial.o: factorial.c
	$(CC) $(CFLAGS) -c factorial.c
