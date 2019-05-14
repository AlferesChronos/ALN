CXXFLAGS = -Wall -std=c++11

all: main.exe

clean:
	rm -f *.o *~ *.exe *.exe.stackdump

main.exe: main.o res_1.o res_Inf.o inversa.o lu.o resol.o product.o
	$(CXX) $^ -o $@

main.o: main.cc

inversa.o: inversa.cc

lu.o: lu.cc

resol.o: resol.cc

res_1.o: res_1.cc

res_Inf.o: res_Inf.cc

product.o: product.cc
