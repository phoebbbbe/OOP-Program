.PHONY: all
all: bin/test main

main: src/main.cpp
	g++ -std=c++11 src/main.cpp -o bin/main
bin/vector: src/vector.cpp src/length.h
	g++ -std=c++11 src/vector.cpp -o bin/vector

bin/test: test/ut_main.cpp test/length_test.h bin
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread
# -fno-elide-constructors -g

.PHONY: bin
bin: 
	mkdir -p bin

.PHONY: clean
clean:
	rm -f bin/*
