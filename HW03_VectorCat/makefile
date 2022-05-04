.PHONY: dirs clean stat

all: bin/ut_all
	
bin/ut_all: dirs test/ut_main.cpp test/ut_cat.h src/cat.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

dirs:
	mkdir -p bin

clean: dirs
	rm bin/*

stat:
	wc src/* test/*
