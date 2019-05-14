CXXFLAGS = -Wall -std=c++11

all: main.exe

clean:
	rm -f *.o *~ *.exe *.exe.stackdump

main.exe: main.o inversa.o lu.o resol.o transposada.o residu.o  res_1.o product.o res_Inf.o
	$(CXX) $^ -o $@

