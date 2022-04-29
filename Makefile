main: main.o pretty-printing.o
	g++ -o main main.o pretty-printing.o

main.o: main.cpp pretty-printing.h
	g++ -c main.cpp

pretty-printing.o: pretty-printing.cpp pretty-printing.h
	g++ -c pretty-printing.cpp
	
clean: 
	rm -f main main.o pretty-printing.o
