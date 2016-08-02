CC = g++
CXX = g++
CPPFLAGS = -I../include -std=c++11 -Wall -Wextra -g
LDFLAGS = -std=c++11

.PHONY : clean TAGS all

all : main
	./main
main:main.cpp your_vector.o

your_vector.o:your_vector.cpp

clean :
	-rm -rf *.o $(EXENAME) *.dSYM

TAGS : clean all
