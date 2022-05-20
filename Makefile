all: sharedq.o main.o
	$(CXX) --std=c++17 -g -o main main.o sharedqueue.o

main.o:
	$(CXX) --std=c++17 -g -c main.cpp -o main.o
sharedq.o:
	$(CXX) --std=c++17 -g -c sharedqueue.cpp -o sharedqueue.o

clean:
	rm *.o main
