# for C
CC = gcc
CFLAGS = -Wall
# for C++
# CXX = g++
# CXXFLAGS = -Wall

hello: hello.o factorial.o greeting.o
	$(CC) $^ -o $@

hello.o: hello.c
	$(CC) $(CFLAGS) -c $<

greeting.o: greeting.c
	$(CC) $(CFLAGS) -c $<

factorial.o: factorial.c
	$(CC) $(CFLAGS) -c $<
