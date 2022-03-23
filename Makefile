lab1: file_in.o
	g++ file_in.o -o lab1

lab2: Calculator.o
	g++ Calculator.o -o lab2

Calculator.o: Calculator.cpp
	g++ -c Calculator.cpp
	
file_in.o: file_in.cpp
	g++ -c file_in.cpp
