.PHONY: default test coverage clean cleancoverage

CFLAGS=-std=c++11

### Actual Program
default: main

main: main.o
	g++ ${CFLAGS} main.o -o main

main.o: main.cpp vector.h vector.hpp
	g++ ${CFLAGS} -c main.cpp

### Test Suite

# Generates coverage reports
coverage: test
	gcov -mr test_vector.cpp

# Builds and runs tests
test: CFLAGS=--coverage
test: testsuite
	@./testsuite

testsuite: test_main.o test_vector.o
	g++ ${CFLAGS} $^ -o testsuite

test_vector.o: test_vector.cpp vector.h vector.hpp
	g++ ${CFLAGS} -c test_vector.cpp

test_main.o: test_main.cpp
	g++ -O3 -c test_main.cpp

cleancoverage:
	-@rm -f *.gcov *.gcno *.gcda

clean: cleancoverage
	-@rm -f *.o
	-@rm -f testsuite
	-@rm -f main
