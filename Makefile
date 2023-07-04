all: DQtest DQarraytest
DQtest: DQtest.o
	g++ -Wall -o DQtest DQtest.o  
DQtest.o: DQtest.cpp deque.h
	g++ -Wall -o DQtest.o -c DQtest.cpp
DQarraytest: DQarraytest.o
	g++ -Wall -o DQarraytest DQarraytest.o
DQarraytest.o: DQarraytest.cpp deque.h
	g++ -Wall -o DQarraytest.o -c DQarraytest.cpp
clean:
	rm -f DQtest DQarraytest *.o 
