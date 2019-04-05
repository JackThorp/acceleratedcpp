
exec: main.o string_list.o
	g++ build/main.o build/string_list.o -o build/exec

main.o: main.cpp
	g++ -c main.cpp -o build/main.o

string_list.o: String_list.cpp
	g++ -c String_list.cpp -o build/string_list.o

.PHONY: clean

clean:
	rm -rf build/*


