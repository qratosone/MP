all:test.out your_vector.out
	./test.out
test.out:test.cpp
	g++ -o test.out test.cpp -std=c++11
your_vector.out:your_vector.cpp
	g++ -o your_vector.out your_vector.cpp
clean:
	rm *.out
