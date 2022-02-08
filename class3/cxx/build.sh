#! /bin/bash

g++ -c hello.cxx
g++ -c greeting.cxx
g++ -c factorial.cxx
g++ hello.o greeting.o factorial.o -o hello
