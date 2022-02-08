#! /bin/bash

g++ -c hello.cxx
g++ -c greeting.cxx
g++ hello.o greeting.o -o hello
