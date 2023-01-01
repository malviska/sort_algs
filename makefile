CC = g++
CXXFLAGS = -std=c++11 -g -Wall
#CXXFLAGS = -std=c++11 -O3 -Wall

# folders
B = ./obj
BIN = ./bin
I = ./include
S = ./src
T = ./tests

all: main

main: clc ${B}/item.o ${B}/item_loaded.o ${B}/methods.o ${B}/quicksort.o ${B}/quicksort_stack.o ${B}/quicksort_stack_smart.o ${B}/quicksort_selection.o ${B}/quicksort_median.o ${B}/mergesort.o ${B}/heapsort.o  ${B}/main.o
	${CC} ${CXXFLAGS} ${B}/* -o ${BIN}/main

test: clc ${B}/item.o ${B}/item_loaded.o ${B}/methods.o ${B}/quicksort.o ${B}/quicksort_stack.o ${B}/quicksort_stack_smart.o ${B}/quicksort_selection.o ${B}/quicksort_median.o ${B}/mergesort.o ${B}/heapsort.o ${B}/test.o
	${CC} ${CXXFLAGS} ${B}/* -o ${BIN}/test


${B}/main.o: ${S}/main.cpp
	${CC} ${CXXFLAGS} -c ${S}/main.cpp -o ${B}/main.o -I ${I} 

${B}/test.o: ${T}/main.test.cpp
	${CC} ${CXXFLAGS} -c ${T}/main.test.cpp -o ${B}/test.o -I ${I}

${B}/heapsort.o: ${I}/heapsort.hpp ${S}/heapsort.cpp
	${CC} ${CXXFLAGS} -c ${S}/heapsort.cpp -o ${B}/heapsort.o -I ${I}

${B}/mergesort.o: ${I}/mergesort.hpp ${S}/mergesort.cpp
	${CC} ${CXXFLAGS} -c ${S}/mergesort.cpp -o ${B}/mergesort.o -I ${I}

${B}/quicksort_stack_smart.o: ${I}/quicksort_stack_smart.hpp ${S}/quicksort_stack_smart.cpp 
	${CC} ${CXXFLAGS} -c ${S}/quicksort_stack_smart.cpp -o ${B}/quicksort_stack_smart.o -I ${I} 


${B}/quicksort_stack.o: ${I}/quicksort_stack.hpp ${S}/quicksort_stack.cpp 
	${CC} ${CXXFLAGS} -c ${S}/quicksort_stack.cpp -o ${B}/quicksort_stack.o -I ${I} 

${B}/quicksort_selection.o: ${I}/quicksort_selection.hpp ${S}/quicksort_selection.cpp 
	${CC} ${CXXFLAGS} -c ${S}/quicksort_selection.cpp -o ${B}/quicksort_selection.o -I ${I} 

${B}/quicksort_median.o: ${I}/quicksort_median.hpp ${S}/quicksort_median.cpp 
	${CC} ${CXXFLAGS} -c ${S}/quicksort_median.cpp -o ${B}/quicksort_median.o -I ${I} 

${B}/quicksort.o: ${I}/quicksort.hpp ${S}/quicksort.cpp 
	${CC} ${CXXFLAGS} -c ${S}/quicksort.cpp -o ${B}/quicksort.o -I ${I} 

${B}/item.o: ${I}/item.hpp ${S}/item.cpp 
	${CC} ${CXXFLAGS} -c ${S}/item.cpp -o ${B}/item.o -I ${I} 

${B}/item_loaded.o: ${I}/item_loaded.hpp ${S}/item_loaded.cpp 
	${CC} ${CXXFLAGS} -c ${S}/item_loaded.cpp -o ${B}/item_loaded.o -I ${I} 


${B}/methods.o: ${I}/methods.hpp ${S}/methods.cpp
	${CC} ${CXXFLAGS} -c ${S}/methods.cpp -o ${B}/methods.o -I ${I} 

clean:
	@rm -rf $(B)/* $(BIN)/*

clc:
	@rm -rf $(BIN)/* $(B)/main.o $(B)/test.o