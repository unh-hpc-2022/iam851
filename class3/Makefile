# for C
CC = gcc
CFLAGS = -Wall
# for C++
# CXX = g++
# CXXFLAGS = -Wall

hello: hello.o factorial.o greeting.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<
