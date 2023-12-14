.PHONY: directories clean stat

all: directories bin/ut_all

bin/ut_all: test/ut_main.cpp test/ut_alcohol.h test/ut_algorithm.h test/ut_order.h test/ut_sour.h test/ut_tequila.h src/alcohol.h src/algorithm.h src/order.h src/sour.h src/tequila.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all_gcovr -lgtest -pthread --coverage -fkeep-inline-functions -fno-inline -fno-inline-small-functions -fno-default-inline -g -O0

directories:
	mkdir -p bin

clean:
	rm -rf bin *.gcov *.gcda *.gcno *.html *.css

stat:
	wc src/* test/*
