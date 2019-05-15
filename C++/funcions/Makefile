CXXFLAGS = -Wall -std=c++11 -O2

all: main.exe

clean:
	rm -f main.exe *.o

main.exe: main.o funcions.o
	$(CXX) $^ -o $@

main.o: main.cpp funcions.h
funcions.o: funcions.cpp funcions.h