all: main

main: main.o sistema.o lu.o resol.o
	g++ -O2 main.o sistema.o lu.o resol.o -o main

main.o: main.cpp
	g++ -O2 -c main.cpp

sistema.o: sistema.cpp
	g++ -O2 -c sistema.cpp

lu.o: lu.cpp
	g++ -O2 -c lu.cpp

resol.o: resol.cpp
	g++ -O2 -c resol.cpp

clean:
	rm -f *.o *~

mrproper: clean
	rm -f main

.PHONY: all clean mrproper
