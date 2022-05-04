.PHONY: all
all: leaktest ut_all

leaktest: leaker.cpp
	g++ leaker.cpp -o leaker

ut_all: ut_main.cpp
	g++ -std=c++11 -Wfatal-errors ut_main.cpp -o ut_all -lgtest -lpthread

.PHONY: clean
clean:
	rm -f leaker
	rm -f ut_all