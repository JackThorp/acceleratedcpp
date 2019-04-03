

.PHONY: clean

exec: Student_info.o main.o 
	g++ ./build/Student_info.o ./build/main.o -o exec

main.o: Student_info.o
	g++ -c main.cpp -o ./build/main.o

Student_info.o:
	g++ -c Student_info.cpp -o ./build/Student_info.o

clean: 
	rm -rf build/*


