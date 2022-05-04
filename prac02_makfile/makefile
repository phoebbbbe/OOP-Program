hello.out: hello.o 2.o 3.o
	g++ -std=c++11 -o hello.out hello.o 2.o 3.o

hello.o: hello.cpp a.h
	g++ -std=c++11 -c hello.cpp
2.o: 2.cpp b.h
	g++ -std=c++11 -c 2.cpp
3.o: 3.cpp a.h b.h c.h
	g++ -std=c++11 -c 3.cpp

clean:
	rm -f 2.o 3.o hello.o hello.out