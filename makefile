all: your_vector.out
	./your_vector.out
your_vector.out:your_vector.cpp
	g++ -o your_vector.out your_vector_solutions.cpp
clean:
	rm your_vector.out
