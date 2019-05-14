all: main

main: main.o matrius.o pr.o
	$(CXX) -O2 main.o matrius.o pr.o -omain

main.o: main.cc
	$(CXX) -O2 -c main.cc

matrius.o: matrius.cc
	$(CXX) -O2 -c matrius.cc

pr.o: pr.cc
	$(CXX) -O2 -c pr.cc

clean:
	rm -f *.o *~

mrproper: clean
	rm -f main

.PHONY: all clean mrproper
