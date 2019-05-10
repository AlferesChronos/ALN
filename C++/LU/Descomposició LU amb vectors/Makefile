CXXFLAGS = -Wall -std=c++11

all: main.exe

clean:
	rm -f *.o *~ *.exe *.exe.stackdump

main.exe: main.o sistema.o lu.o resol.o residu.o res_2.o res_Inf.o
	$(CXX) $^ -o $@

main.o: main.cc

sistema.o: sistema.cc

lu.o: lu.cc

resol.o: resol.cc

residu.o: residu.cc

res_2.o: res_2.cc

res_Inf.o: res_Inf.cc
