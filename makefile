lab5:HugeInt.o main.o
	g++ -o lab5 main.o HugeInt.o
HugeInt.o:HugeInt.cpp HugeInt.h
	g++ -c HugeInt.cpp
main.o:main.cpp HugeInt.h
	g++ -c main.cpp
clean:
	rm HugeInt*.o
