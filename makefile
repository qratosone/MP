CC = g++
CXX = g++
CPPFLAGS = -Iinclude -std=c++11 -Wall -Wextra -g
LDFLAGS = -std=c++11
EXENAME = main test
.PHONY : clean TAGS all

all : $(EXENAME)
	./test
test:src/test.cpp
	$(CXX) $(CPPFLAGS) -o test src/test.cpp
main:your_vector.o src/main.cpp
	$(CXX) $(LDFLAGS) -o main your_vector.o src/main.cpp
your_vector.o:src/your_vector.cpp include/your_vector.h
	$(CXX) $(CPPFLAGS) -c src/your_vector.cpp
clean :
	-rm -rf *.o $(EXENAME) *.dSYM

TAGS : clean all
