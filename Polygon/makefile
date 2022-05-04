.PHONY: directories clean stat

all: directories bin/ut_all

CFLAGS = -std=c++11 -Wfatal-errors
SRC = src/app.h src/shape.h src/triangle.h src/circle.h
TEST = test/ut_app.h test/ut_circle.h test/ut_triangle.h

bin/ut_all: test/ut_main.cpp $(SRC) $(TEST)
	g++ $(CFLAGS) test/ut_main.cpp -o bin/ut_all -lgtest -pthread

directories:
	mkdir -p bin

clean: directories
	rm -rf bin

stat:
	wc src/* test/*
